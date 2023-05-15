/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/


class Solution {
public:
    long long helper(int i, int n, vector<int> &prices, int buy, int capacity, vector<vector<vector<int>>> &dp){
        if(i==n) return 0;
        if(capacity==0) return 0;
        if(dp[i][buy][capacity]!=-1) return dp[i][buy][capacity];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+helper(i+1,n,prices,0,capacity,dp) , helper(i+1,n,prices,1,capacity,dp));
        }else{
            profit=max(prices[i]+helper(i+1,n,prices,1,capacity-1,dp) , helper(i+1,n,prices,0,capacity,dp));
        }
    return dp[i][buy][capacity]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int capacity=2, buy=1;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return helper(0,n,prices,buy,capacity,dp);
    }
};
