/// With K jumps

#include <bits/stdc++.h>
using namespace std;
/*
int helper(int i, int k, int n, vector<int> &arr, vector<int> &dp){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int result=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0){
            int jump=helper(i-j,k,n,arr,dp)+abs(arr[i]-arr[i-j]);
            result=min(result,jump);
        }
    }

return dp[n]=result;
}
*/
int minimumCost(vector<int> &arr, int n, int k)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int result=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
                result=min(result,jump);
            }
        }
        dp[i]=result;
    }
return dp[n-1];
}
