/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:
Input: nums = [1,2,3,4], k = 3
Output: false
*/

class Solution {
public:
    bool helper(int i, int currSum, int target, int k, vector<int> &nums, vector<bool> &dp){
        if(k==0) return true;
        if(currSum>target) return false;
        if(currSum==target) return helper(0,0,target,k-1,nums,dp);
        for(int j=i;j<nums.size();j++){
            if(dp[j]) continue;
            dp[j]=true;
            if(helper(j+1,currSum+nums[j],target,k,nums,dp)) return true;
            dp[j]=false;
            if(currSum==0) break;
        }
    return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k){
        int n=nums.size(), total=accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0 or k>n) return false;
        sort(nums.begin(),nums.end());
        int target=total/k;
        vector<bool> dp(n,false);
        if(nums[0]>target) return false;

    return helper(0,0,target,k,nums,dp);
    }
};
