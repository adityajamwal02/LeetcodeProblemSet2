/*
In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

Example 1:
Input: K = 2, N = 6
A = {10, 22, 5, 75, 65, 80}
Output: 87
Explaination:
1st transaction: buy at 10 and sell at 22.
2nd transaction : buy at 5 and sell at 80.

Example 2:
Input: K = 3, N = 4
A = {20, 580, 420, 900}
Output: 1040
Explaination: The trader can make at most 2
transactions and giving him a profit of 1040.

Example 3:
Input: K = 1, N = 5
A = {100, 90, 80, 50, 25}
Output: 0
Explaination: Selling price is decreasing
daily. So seller cannot have profit.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maxProfit() which takes the values K, N and the array A[] as input parameters and returns the maximum profit.

Expected Time Complexity: O(N*K)
Expected Auxiliary Space: O(N*K)
*/

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        int profit=0;
        for(int i=N-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int k=1;k<=K;k++){
                    if(buy==0){
                        profit=max(dp[i+1][0][k],-A[i]+dp[i+1][1][k]);
                    }else{
                        profit=max(dp[i+1][1][k],A[i]+dp[i+1][0][k-1]);
                    }
                dp[i][buy][k]=profit;
                }
            }
        }
    return dp[0][0][K];
    }
};



