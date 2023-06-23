/*
Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.

Example 1:
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

Example 2:
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".

Example 3:
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
*/

class Solution {
public:
    int mod=1e9+7;

    int helper(int i, int n, string &s, vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        vector<int> seen(26);
        int ans=0;
        for(int j=i;j<n;j++){
            if(seen[s[j]-'a']) continue;
            seen[s[j]-'a']=1;
            ans=(ans+1+helper(j+1,n,s,dp))%mod;
        }
    return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        int result=helper(0,n,s,dp);

    return result;
    }
};
