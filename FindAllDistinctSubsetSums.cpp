/*
Given a set of integers, find all distinct sums that can be generated from the subsets of the given sets.


Example 1:

Input: nums = {1,2}
Output: {0,1,2,3}
Explanation: Four distinct sums can be
calculated which are 0, 1, 2 and 3.
0 if we do not choose any number.
1 if we choose only 1.
2 if we choose only 2.
3 if we choose 1 and 2.

Example 2:

Input: nums = {1,2,3}
Output: {0,1,2,3,4,5,6}
Explanation: Seven distinct sum can be calculated
which are 0, 1, 2, 3, 4, 5 and 6.
0 if we do not choose any number.
1 if we choose only 1.
2 if we choose only 2.
3 if we choose only 3.
4 if we choose 1 and 3.
5 if we choose 2 and 3.
6 if we choose 1, 2 and 3.



Your Task:
You don't need to read or print anything. Your task is to complete the function DistinictSum() which takes nums as input parameter and returns a list containing the distinict sum in increasing order,


Expected Time Complexity: O(n * sum) where sum = sum of all elements of nums.
Expected Space Complexity: O(n * sum)
*/


/// Recursive

class Solution {
public:
    void generateSumCombinations(int i, int sum, vector<int> &arr, int n, set<int> &st){
        if(i>n) return;
        if(i==n){
            st.insert(sum);
            return;
        }
        generateSumCombinations(i+1,sum+arr[i],arr,n,st);
        generateSumCombinations(i+1,sum,arr,n,st);
    }

	vector<int> DistinctSum(vector<int>nums){
	    set<int> st;
	    generateSumCombinations(0,0,nums,nums.size(),st);
	    vector<int> result;
	    for(auto it : st){
	        result.push_back(it);
	    }
	return result;
	 }

};

/// Memoized

class Solution {
public:
    void generateSumCombinations(int i, int sum, vector<int> &arr, int n, set<int> &st, vector<vector<int>> &dp){
        if(i==n){
            st.insert(sum);
            return;
        }
        if(dp[i][sum]!=-1) return;

        generateSumCombinations(i+1,sum+arr[i],arr,n,st,dp);    // pick
        generateSumCombinations(i+1,sum,arr,n,st,dp);           // not pick

    dp[i][sum]=0;
    }

	vector<int> DistinctSum(vector<int>nums){
	    set<int> st;
	    int total=0;
	    for(auto it : nums) total+=it;
	    vector<vector<int>> dp(nums.size()+1,vector<int>(total+1,-1));
	    generateSumCombinations(0,0,nums,nums.size(),st,dp);
	    vector<int> result(st.begin(),st.end());
	return result;
	 }

};

/// Optimized (Bitset)

vector<int> generateSumCombinations(int n, vector<int> &arr){
        vector<int> result;
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=arr[j];
                }
            }
        result.push_back(sum);
        }
    return result;
    }






