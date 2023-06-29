/*
Given two strings S and T of length n and m respectively. Find count of distinct occurrences of T in S as a sub-sequence.

Example 1:
Input:
S = "banana" , T = "ban"
Output: 3
Explanation: There are 3 sub-sequences:
[ban], [ba n], [b an].

Example 2:
Input:
S = "geeksforgeeks" , T = "ge"
Output: 6
Explanation: There are 6 sub-sequences:
[ge], [ ge], [g e], [g e] [g e] and [ g e].

Your Task:
You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument S and T and returns the count of the sub-sequences modulo 109 + 7.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).
*/

/// Memoization:

class Solution
{
    public:
    int mod=1e9+7;
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j==-1) return 1;
        if(i==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0, notTake=0;
        if(s[i]==t[j]){
            take=helper(i-1,j-1,s,t,dp);
        }
        notTake=helper(i-1,j,s,t,dp);

    return dp[i][j]=(take%mod + notTake%mod)%mod;
    }
    int subsequenceCount(string S, string T)
    {
        int n=S.size(), m=T.size();
        if(m>n) return -1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(n-1,m-1,S,T,dp);
    }
};


/// Tabulation

class Solution
{
public:
    int mod=1e9+7;
    int subsequenceCount(string S, string T)
    {
        int n=S.size(), m=T.size();
        if(m>n) return -1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0; i<=n; i++)
            dp[i][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(S[i-1] == T[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};
