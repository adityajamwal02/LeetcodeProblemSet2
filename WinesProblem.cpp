/*
Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can sell the first or the last wine in the row.
Let the initial profits from the wines be P1, P2, P3…Pn. In the Yth year, the profit from the ith wine will be Y*P[i].
The goal is to calculate the maximum profit that can be earned by selling all the wines.
Input: Price of wines: 2 4 6 2 5
Output: beg end end beg beg
64
*/

#include<bits/stdc++.h>
using namespace std;

/// Recursive Solution

int solve(int i, int j, int price[], int year){
    if(i>j) return 0;
    if(i==j) return year*price[i];
    int left=price[i]*year + solve(i+1,j,price,year+1);
    int right=price[j]*year + solve(i,j-1,price,year+1);
    return max(left,right);
}


/// Memoization

int dp[100][100];
int helper(int i, int j, int price[], int year){
    if(i>j) return 0;
    if(i==j) return year*price[i];
    if(dp[i][j]!=-1) return dp[i][j];
    int left=price[i]*year + solve(i+1,j,price,year+1);
    int right=price[j]*year + solve(i,j-1,price,year+1);
    return dp[i][j]=max(left,right);
}

/// Tabulation


int maxProfitTabulation(int price[], int n){
    vector<vector<int>> dpArr(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i==j){
                dpArr[i][i]=n*price[i];
            }else if(i<j){
                int y=n-(j-i);
                int pick_left=price[i]*y + dpArr[i+1][j];
                int pick_right=price[j]*y + dpArr[i][j-1];
                dpArr[i][j]=min(pick_left,pick_right);
            }
        }
    }
    return dpArr[0][n-1];
}


int maxProfit(int price[], int n){
    memset(dp,-1,sizeof(dp));
    return helper(0,n-1,price,1);

    //return solve(0,n-1,price,1);
}


int main(){
    int n=5;
    int price[5]={2,4,6,2,5};
    int ans=maxProfitTabulation(price,n);
    cout<<ans<<endl;
    return 0;
}
