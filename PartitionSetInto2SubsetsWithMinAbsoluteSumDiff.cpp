/// Partition A Set Into Two Subsets With Minimum Absolute Sum Difference

/* Idea : Use subset sum equals target to get S1 (sum1), so S2 (sum2) will be target-S1, considering these 2 for abs(S1-S2)
   The last row, will indicate the presence or possibility of the subset sum equals to a particular target (target can be from 0 to totalSum)
*/


/// Solution 1 : Subset Sum Concept (DP) [Works only for positive numbers]. if negative also present, go with solution2

#include<bits/stdc++.h>
using namespace std;

bool helper(int i, int n, int target, vector<int> &arr, vector<vector<int>> &dp){
	if(target==0) return true;
	if(i==0){
		return target==arr[0];
	}
	if(dp[i][target]!=-1) return dp[i][target];
	bool take=false;
	bool notTake=helper(i-1,n,target,arr,dp);
	if(target-arr[i]>=0){
		take=helper(i-1,n,target-arr[i],arr,dp);
	}
	return dp[i][target]=take|notTake;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum=accumulate(arr.begin(),arr.end(),0);
	vector<vector<int>> dp(n+1,vector<int>(totalSum+1,-1));
	for(int i=0;i<=totalSum;i++){
		bool temp=helper(n-1,n,i,arr,dp);
	}
	int result=INT_MAX;
	for(int i=0;i<=totalSum;i++){
		if(dp[n-1][i]==true){
			int currDiff=abs(i-(totalSum-i));
			result=min(result,currDiff);
		}
	}
	return result;
}

/// Solution 2 : Meet in the middle (Binary Search + Recursion + Bitmask (for storing various subsets based on parity) + Map/set)

// Meet in the middle algorithm

    void distributeSums(vector<int> &vec, map<int,vector<int>> &mp){
        int n=vec.size();
        for(int i=0;i<(1<<n);i++){
            int currSum=0;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    currSum+=vec[j];
                }
            }
            mp[__builtin_popcount(i)].push_back(currSum);
        }
        for(auto &it : mp){
            vector<int> &temp=it.second;
            sort(temp.begin(),temp.end());
            temp.resize(unique(temp.begin(),temp.end())-temp.begin());
        }
    }

    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2, total=accumulate(nums.begin(),nums.end(), 0), result=1e9;
        vector<int> arr1(n), arr2(n);                       // arr1->left, arr2->right
        map<int,vector<int>> sumLeft, sumRight;
        for(int i=0;i<n;i++){
            arr1[i]=nums[i];                                // Dividing first half into arr1
        }
        for(int i=0;i<n;i++){
            arr2[i]=nums[i+n];                              // Dividing second half into arr2
        }
        distributeSums(arr1,sumLeft);                       // Distributing sum over Left
        distributeSums(arr2,sumRight);                      // Distributing sum over Right
        for(auto &it : sumLeft){                            // For every Element in LeftArray
            for(auto &x : it.second){                       // For vector corresponding to each left map
                if(sumRight.count(n-it.first)==0) break;
                vector<int> &vec=sumRight[n-it.first];      // For search in sorted part of right array
                int low=0, high=vec.size()-1;
                while(low<=high){                           // Binary Search (Over to minimize LeftOver)
                    int mid=low+(high-low)/2;
                    int leftOver=abs(total-2*(x+vec[mid]));
                    int s_left = mid-1 >= 0 ? abs(total-2*(x+vec[mid-1])) : 1e9;
                    int s_right = mid+1 < vec.size() ? abs(total-2*(x+vec[mid+1])) : 1e9;
                    if(s_left > leftOver){
                        result=min(result,leftOver);
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }
            }
        }
    return result;
    }

