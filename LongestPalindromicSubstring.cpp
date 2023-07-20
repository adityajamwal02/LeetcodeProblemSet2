/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/

/// String Based Solution

class Solution {
public:
    int check(string &s, int l, int r){
        while(l>=0 and r<s.size() and s[l]==s[r]){
            l--;
            r++;
        }
    return r-l-1;
    }
    string longestPalindrome(string s) {
        int ans=0, st=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int len1=check(s,i,i);
            int len2=check(s,i,i+1);
            int len=max(len1,len2);
            if(len>ans){
                ans=len;
                st=i-(len-1)/2;
            }
        }
    return s.substr(st,ans);
    }
};

/// DP Solution

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(), maxVal=1;
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        string result;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            result=s.substr(i,1);
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                result=s.substr(i,2);
            }
        }
        for(int i=n-3;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(s[i]==s[j] and dp[i+1][j-1]){
                    int currLen=j-i+1;
                    dp[i][j]=1;
                    if(currLen>maxVal){
                        maxVal=currLen;
                        result=s.substr(i,currLen);
                    }
                }
            }
        }
    return result;
    }
};
