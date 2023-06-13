/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3
*/

/// Concept of House Robber 1 used but in 2 arrays (in partition):

/// Memoization

class Solution {
public:
    int helper(int i, int n, vector<int> &vec, vector<int> &dp){
        if(i==0) return vec[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=vec[i]+helper(i-2,n,vec,dp);
        int notPick=helper(i-1,n,vec,dp);
    return dp[i]=max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n+1,-1), dp2(n+1,-1);
        if(n==1) return nums[0];
        vector<int> arr1, arr2;
        for(int i=0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        int ans1=helper(n-2,n,arr1,dp1);
        int ans2=helper(n-2,n,arr2,dp2);
    return max(ans1,ans2);
    }
};

/// Tabulation

class Solution {
public:
    int helper(int n, vector<int> &vec){
        vector<int> dp(n+1,0);
        dp[0]=vec[0];
        for(int i=1;i<n;i++){
            int pick=vec[i];
            if(i>1) pick+=dp[i-2];
            int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
        }
    return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n+1,0), dp2(n+1,0);
        if(n==1) return nums[0];
        vector<int> arr1, arr2;
        for(int i=0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        int ans1=helper(n-1,arr1);
        int ans2=helper(n-1,arr2);
    return max(ans1,ans2);
    }
};

/// Space Optimized

class Solution {
public:
    int helper(int n, vector<int> &vec){
        int prev2=0, prev=vec[0];
        for(int i=1;i<n;i++){
            int pick=vec[i];
            if(i>1) pick+=prev2;
            int notPick=prev;
            int curr=max(pick,notPick);
        prev2=prev;
        prev=curr;
        }
    return prev;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> arr1, arr2;
        for(int i=0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        int ans1=helper(n-1,arr1);
        int ans2=helper(n-1,arr2);
    return max(ans1,ans2);
    }
};
