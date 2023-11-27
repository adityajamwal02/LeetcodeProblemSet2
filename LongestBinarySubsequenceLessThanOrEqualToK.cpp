/*
You are given a binary string s and a positive integer k.
Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
Note:
The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Example 1:
Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.

Example 2:
Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
*/

class Solution {
public:
    int helper(int i, int n, int k, string &s, vector<int> &dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=0;
        if((s[i-1]-'0')*pow(2,n-i)<=k){
            take=1+helper(i-1,n,k-(s[i-1]-'0')*pow(2,n-i),s,dp);
        }
        int notTake=helper(i-1,n,k,s,dp);

    return dp[i]=max(take,notTake);
    }

    int longestSubsequence(string s, int k){
        int n=s.size(), result=0;
        vector<int> dp(1001,-1);

    return helper(n,n,k,s,dp);
    }
};
