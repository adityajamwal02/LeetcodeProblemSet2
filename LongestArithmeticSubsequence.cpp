/*
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

Example 1:
Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length = 3.

Example 2:
Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].

Example 3:
Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].
*/


/// DP Tabulation

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(), result=0;
        vector<vector<int>> dp(n,vector<int>(2001,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=1000+(nums[i]-nums[j]);
                dp[i][diff]=1+dp[j][diff];
                result=max(result,dp[i][diff]);
            }
        }
    return result;
    }
};


/// Passed Code on GFG :

//User function template for C++

class Solution{
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n==1) return 1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
        }
        int result=2;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int diff=A[j]-A[i];
                int count=2;
                int s=A[j];
                while(mp.find(diff+s)!=mp.end()){
                    count++;
                    s=diff+s;
                }
            result=max(result,count);
            }
        }
    return result;
    }
};
