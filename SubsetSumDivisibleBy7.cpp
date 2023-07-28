/// Given an array of size n, find the number of subsets with a sum divisible by 7. Answer return with mod 1e9+7

#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int counter=0;

void helper(int i, int sum, int n, vector<int> &nums, vector<vector<int>> &dp){
    if(i==n){
        if(sum%7==0) counter++;
        counter%=mod;
    }
    if(dp[i][sum]!=-1) return;
    helper(i+1,sum+nums[i],n,nums,dp);
    helper(i+1,sum,n,nums,dp);

dp[i][sum]=0;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        helper(0,0,n,nums,dp);
        cout<<counter<<endl;
    }

    return 0;
}
