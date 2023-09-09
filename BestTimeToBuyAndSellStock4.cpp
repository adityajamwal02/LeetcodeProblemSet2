/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

/// memoization

class Solution {
public:
    int helper(int i, int n, int buy, int cap, vector<int> &prices, int dp[10001][2][101]){
        if(i==n or cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit=0;
        if(buy==0){
            profit=max(helper(i+1,n,0,cap,prices,dp),-prices[i]+helper(i+1,n,1,cap,prices,dp));
        }else{
            profit=max(helper(i+1,n,1,cap,prices,dp),+prices[i]+helper(i+1,n,0,cap-1,prices,dp));
        }
    return dp[i][buy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int dp[10001][2][101];
        memset(dp,-1,sizeof(dp));

    return helper(0,n,0,k,prices,dp);
    }
};

/// Tabulation

class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(cap+1,0)));
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<cap+1;k++){
                    if(j==0){
                        profit=max(dp[i+1][0][k],-prices[i]+dp[i+1][1][k]);
                    }else{
                        profit=max(dp[i+1][1][k],+prices[i]+dp[i+1][0][k-1]);
                    }
                dp[i][j][k]=profit;
                }
            }
        }
    return dp[0][0][cap];
    }
};

