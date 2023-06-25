/*
You are given a binary array nums.
A subarray of an array is good if it contains exactly one element with the value 1.
Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [0,1,0,0,1]
Output: 3
Explanation: There are 3 ways to split nums into good subarrays:
- [0,1] [0,0,1]
- [0,1,0] [0,1]
- [0,1,0,0] [1]

Example 2:
Input: nums = [0,1,0]
Output: 1
Explanation: There is 1 way to split nums into good subarrays:
- [0,1,0]
*/

class Solution {
public:
    long long mod=1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                dp.push_back(i);
            }
        }
        long long result=0;
        if(dp.size()>0) result=1;
        long long ans=result;
        for(int i=dp.size()-2;i>=0;i--){
            int leftIndex=dp[i];
            int rightIndex=dp[i+1];
            int diff=rightIndex-leftIndex;
            long long multiply=((long long)diff%mod*(long long)ans%mod)%mod;
            ans=multiply;
            result=multiply;
        }
    return (int)result;
    }
};
