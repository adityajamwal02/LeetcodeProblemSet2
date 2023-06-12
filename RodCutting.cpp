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

/// Memoization Solution

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

/// Tabulation Solution

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notTaken=dp[i-1][j];
                int taken=INT_MIN;
                if(i+1<=j){
                    taken=price[i]+dp[i][j-i-1];
                }
            dp[i][j]=max(taken,notTaken);
            }
        }
    return dp[n-1][n];
    }
};


/// Space Optimized (IDEA: dp[ind][length] =  max(dp[ind-1][length] ,dp[ind][length-(ind+1)]))

int cutRod(vector<int>& price,int N) {

    vector<int> cur (N+1,0);

    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];
    }

    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){

             int notTaken = 0 + cur[length];

             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];

             cur[length] = max(notTaken,taken);
        }
    }

    return cur[N];
}
