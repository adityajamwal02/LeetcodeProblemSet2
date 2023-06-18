/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        int len=1;
        vector<int> dp(nums.size(), 1);

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i], 1+dp[j]);
                    len=max(len, dp[i]);
                }

            }
        }
    return len;
    }
};


/// Optimized Approach (Upper bound + BS) + DP)

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp;
        dp.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>dp[dp.size()-1]){
                dp.push_back(a[i]);
            }else{
                *lower_bound(dp.begin(),dp.end(),a[i])=a[i];
            }
        }
    return dp.size();
    }
};
