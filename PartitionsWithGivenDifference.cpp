/// Partitions With Given Difference

#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int helper(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
    if(i==0){
        if(target==0 and nums[0]==0) return 2;
        if(target==0 or nums[0]==target) return 1;
    return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int take=0;
    int notTake=helper(i-1,target,nums,dp);
    if(target-nums[i]>=0){
        take=helper(i-1,target-nums[i],nums,dp);
    }
return dp[i][target]=(take%mod+notTake%mod)%mod;
}

int countPartitions(int n, int d, vector<int> &nums) {

    long long totalSum=accumulate(nums.begin(),nums.end(),0);
    long long target=(totalSum-d)/2;
    if(totalSum-d < 0) return 0;
    if((totalSum-d)%2==1) return 0;

    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

return helper(n-1,target,nums,dp);
}


/// Tabulation

    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        int target=(totalSum-d)/2;
        if(totalSum-d<0 or (totalSum-d)%2==1) return 0;

        vector<vector<int>> dp(n+1,vector<int>(target+1,0));

        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;

        if(arr[0]!=0 and target-arr[0]>=0) dp[0][arr[0]]=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int take=0;
                int notTake=dp[i-1][j];
                if(j-arr[i]>=0){
                    take=dp[i-1][j-arr[i]];
                }
            dp[i][j]=(take%mod+notTake%mod)%mod;
            }
        }
    return dp[n-1][target];
    }
