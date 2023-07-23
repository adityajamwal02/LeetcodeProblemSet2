/*
Given two positive integers n and x.
Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.
Since the result can be very large, return it modulo 109 + 7.
For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

Example 1:
Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.

Example 2:
Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.
*/


class Solution {
public:
    int mod=1e9+7;
    int helper(int i, int num, int x, vector<vector<int>>& dp) {
        if(i<0)
            return 0;
        if(i==0)
            return 1;

        if(pow(num, x) > i)
            return 0;

        if(dp[i][num] != -1) return dp[i][num];

        int temp = pow(num, x);

        int avoid=helper(i-temp,num+1,x,dp);
        int consider=helper(i,num+1,x,dp);

    return dp[i][num]=(avoid%mod + consider%mod)%mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(n,1,x,dp);
    }
};
