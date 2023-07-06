/*
The cost of stock on each day is given in an array price[] of size n. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day, Find the maximum profit which you can get.

Note: You can only hold one stock at a time.

Example 1:
Input:
n = 4
a = {3, 4, 1, 5}
Output:
5
Explanation:
We can buy stock on day 1 (at price 3) and sell it on
day 2 (at price 4) profit will be 4-3=1,
We can buy another stock on day 3 (at price 1) and sell
it on day 4 (at price 5) profit will be 5-1=4,
which will give us maximum profit of 5.

Example 2:
Input:
n = 5
a = {1, 3, 5, 7, 9}
Output:
8
Explanation:
We can buy stock on day 1 (at price 1) and sell it on
day 5 (at price 9),
which will give us maximum profit of 8.
Your Task:
Complete stockBuyAndSell() function which takes an array of Prices as input and returns the maximum profit achieved as described in the problem statement.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
*/


/// Greedy Approach

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int result=0;
        for(int i=1;i<n;i++){
            int temp=prices[i]-prices[i-1];
            if(temp>0) result+=temp;
        }
    return result;
    }
};


/// Recursive Solution + Memoization

class Solution {
  public:
    int helper(int i, int j, vector<int> &prices, vector<vector<int>> &dp){
        // i -> index, j -> buy
        if(i==prices.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j){
            int op1=-prices[i]+helper(i+1,0,prices,dp);  // take (buy)
            int op2=helper(i+1,1,prices,dp);    // skip
        return dp[i][j]=max(op1,op2);
        }else{
            int op1=prices[i]+helper(i+1,1,prices,dp);   // take (sell)
            int op2=helper(i+1,0,prices,dp);    // skip
        return dp[i][j]=max(op1,op2);
        }
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
    return helper(0,1,prices,dp);
    }
};

/// Tabulation

class Solution {
  private:
    int solveTab(vector<int> &prices){
        //create and initialize dp array
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        //analyse base case

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    //buy stock
                    int case1=-prices[index]+dp[index+1][0];

                    //skip
                    int case2=0+dp[index+1][1];

                    dp[index][buy]=max(case1,case2);
                }
                else{
                    //sell stock
                    int case1=prices[index]+dp[index+1][1];

                    //skip
                    int case2=0+dp[index+1][0];

                    dp[index][buy]=max(case1,case2);
                }
            }
        }
        return dp[0][1];
    }
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        return solveTab(prices);
    }
};
