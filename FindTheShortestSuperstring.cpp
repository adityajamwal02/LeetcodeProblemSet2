/*
Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
You may assume that no string in words is a substring of another string in words.

Example 1:
Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.

Example 2:
Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
*/


class Solution {
public:
    string helper(int i, int n, int vis, vector<string> &words, vector<vector<int>> &weight, vector<vector<string>> &dp){
        if(vis==((1<<n)-1)) return "";
        if(!dp[i][vis].empty()) return dp[i][vis];
        int mini=1e9;
        string minString, temp;
        for(int j=0;j<n;j++){
            if((vis&(1<<j))==0){
                temp=words[j].substr(weight[i][j])+helper(j,n,(vis|(1<<j)),words,weight,dp);
                if(temp.size()<mini){
                    mini=temp.size();
                    minString=temp;
                }
            }
        }
    return dp[i][vis]=minString;
    }

    string shortestSuperstring(vector<string>& words){
        int n=words.size(), mini=1e9;
        vector<vector<string>> dp(n+1,vector<string>((1<<n)+1,""));
        vector<vector<int>> weight(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) weight[i][j]=words[i].size();
                else{
                    int k=min(words[i].size(),words[j].size());
                    for(;k>=0;k--){
                        if(words[i].substr(words[i].size()-k)==words[j].substr(0,k)){
                            weight[i][j]=k;
                            break;
                        }
                    }
                }
            }
        }
        string result, temp;
        for(int i=0;i<n;i++){
            int vis=0;
            vis=vis|(1<<i);
            temp=words[i]+helper(i,n,vis,words,weight,dp);
            if(temp.size()<mini){
                mini=temp.size();
                result=temp;
            }
        }
    return result;
    }
};
