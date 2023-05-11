/*
Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
Note: Consider 1-based indexing.

Example 1:
Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and
6, i.e., 5+17=22.

Example 2:
Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
Explanation:
The maximum obtainable value is
24 by cutting the rod into 8 pieces
of length 1, i.e, 8*3=24.

Your Task:
You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
*/

// User function Template for C++

class Solution{
  public:
    int solve(int i, int j, int price[], vector<vector<int>> &dp){
        if(i==0){
            return price[0]*j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int notTake=solve(i-1,j,price,dp);
        int take=INT_MIN;
        if(i+1<=j) take=price[i]+solve(i,j-i-1,price,dp);

    return dp[i][j]=max(take,notTake);
    }

    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return solve(n-1,n,price,dp);
    }
};
