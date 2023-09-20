/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:
Input: nums = [1,5]
Output: 10
*/


class Solution {
public:
/* Memoization
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxVal=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost=(nums[i-1]*nums[k]*nums[j+1])+helper(i,k-1,nums,dp)+helper(k+1,j,nums,dp);
            maxVal=max(maxVal,cost);
        }
    return dp[i][j]=maxVal;
    }
*/
    int maxCoins(vector<int>& nums){
        int n=nums.size();
        //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxVal=INT_MIN;
                for(int k=i;k<=j;k++){
                    int cost=(nums[i-1]*nums[k]*nums[j+1])+dp[i][k-1]+dp[k+1][j];
                    maxVal=max(maxVal,cost);
                }
            dp[i][j]=maxVal;
            }
        }
    return dp[1][n];
    }
};
