/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0
*/

/// Recursive DP

class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy==1){
            return dp[index][buy]=max(-prices[index]+solve(index+1,0,prices,dp), 0+solve(index+1,1,prices,dp));
        }
    return dp[index][buy]=max(prices[index]+solve(index+2,1,prices,dp), 0+solve(index+1,0,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};

/// Optimized

int stockProfit(vector<int> &prices){
    int n=prices.size();
    int k=2;    // k conosidered to be the cooldown period
    int dp[100002][2];
    memset(dp,0,sizeof(dp));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            if(buy==0){
                dp[i][buy]=max(dp[i+1][0],-prices[i]+dp[i+1][1]);
            }else{
                dp[i][buy]=max(dp[i+1][1],+prices[i]+dp[i+k][0]);
            }
        }
    }
return dp[0][0];
}
