/*
There is a strange printer with the following two special properties:
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

Example 1:
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
*/

class Solution {
public:
    int helper(int i, int j, string &s, vector<vector<int>> &dp){
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int result= INT_MAX;
        for(int k=i;k<j;k++){
            result=min(result,helper(i,k,s,dp)+helper(k+1,j,s,dp));
        }
    return dp[i][j] = (s[i]==s[j]) ? result-1 : result;
    }

    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return helper(0,n-1,s,dp);
    }
};
