/*
Given a pair of strings, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:
Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 7 distinct subsequences whereas "ggg" have 4 distinct subsequences.

Example 2:
Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence.
Constraints:
1 <= str1.lenght , str2.length <= 30

Your Task:
You don't need to read input or print anything. Your task is to complete the function betterString() which takes str1 and str2 as input parameters and returns the better string.
*/

class Solution {
  public:
    int mod=1e9+7;

    int helper(int i, int n, string &str, vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        vector<int> seen(26);
        int ans=0;
        for(int j=i;j<n;j++){
            if(seen[str[j]-'a']) continue;
            seen[str[j]-'a']=1;
            ans=(ans+1+helper(j+1,n,str,dp))%mod;
        }
    return dp[i]=ans;
    }


    string betterString(string str1, string str2) {
        int n1=str1.size(), n2=str2.size();
        vector<int> dp1(n1,-1), dp2(n2,-1);

        if(helper(0,n1,str1,dp1) >= helper(0,n2,str2,dp2)) return str1;

    return str2;
    }
};
