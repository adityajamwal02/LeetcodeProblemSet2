/*
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
Return the minimum possible absolute difference.

Example 1:
example-1
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

Example 2:
Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.

Example 3:
example-3
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
*/

/// Meet in middle Algorithm

class Solution {
public:
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
};
