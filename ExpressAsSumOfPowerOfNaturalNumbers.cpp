/*
Given two numbers n and x, find out the total number of ways n can be expressed as the sum of the Xth power of unique natural numbers. As the total number of ways can be very large, so return the number of ways modulo 109 + 7.

Example 1:
Input:
n = 10, x = 2
Output:
1
Explanation:
10 = 12 + 32, Hence total 1 possibility.

Example 2:
Input:
n = 100, x = 2
Output:
3
Explanation:
100 = 102
62 + 82 and 12 + 32 + 42 + 52 + 72
Hence total 3 possibilities.
Your Task:
You don't need to read input or print anything. Complete the function numOfWays() which takes n and x as input parameters and returns the total number of ways n can be expressed as the sum of xth power of unique natural numbers.

Expected Time Complexity: O(n2logn)
Expected Auxiliary Space: O(n)
*/

/// Memoization

//User function Template for C++
class Solution{
    public:
    int mod=1e9+7;
    int helper(int n, int x, int i, int maxLimit,vector<vector<long long>> &dp){
        if(n==0) return 1;
        if(i>maxLimit or n<0) return 0;
        if(dp[n][i]!=-1) return dp[n][i];
        long long int temp=pow(i,x);
        int pick=helper(n-temp,x,i+1,maxLimit,dp);
        int notPick=helper(n,x,i+1,maxLimit,dp);
    return dp[n][i]=(pick+notPick)%mod;
    }
    int numOfWays(int n, int x)
    {
        int maxLimit=pow(n,1.0/x);
        vector<vector<long long>> dp(n+1,vector<long long>(maxLimit+1,-1));
    return helper(n,x,1,maxLimit,dp);
    }
};
