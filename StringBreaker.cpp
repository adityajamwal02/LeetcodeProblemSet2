/// String Breaker : Partition DP


#include <bits/stdc++.h>
using namespace std;

int helper(int i, int n, string s, unordered_map<string,int> &mp, vector<int> &dp){
    if(i==n or mp.find(s.substr(i,n-i))!=mp.end()) return 0;
    if(dp[i]!=-1) return dp[i];
    string result;
    int minBreaks=n<<1;
    for(int j=i;j<n;j++){
        result.push_back(s[j]);
        if(mp.find(result)!=mp.end()){
            int currBreak=1+helper(j+1,n,s,mp,dp);
            minBreaks=min(minBreaks,currBreak);
        }
    }
return dp[i]=minBreaks;
}

int stringBreaker(string s, int wordsCount, vector<string> dictionary)
{
    int n=s.size();
    vector<int> dp(n+1,-1);
    unordered_map<string,int> mp;
    for(auto word : dictionary){
        mp[word]=1;
    }
    int result=helper(0,n,s,mp,dp);
return (result > n ? -1 : result);
}
