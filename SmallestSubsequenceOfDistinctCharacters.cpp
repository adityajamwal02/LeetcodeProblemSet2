/*
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26,0),vis(26,0);
        string result="";
        int n=s.size();
        for(int i=0;i<n;i++) cnt[s[i]-'a']++;
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']--;
            if(!vis[s[i]- 'a']){
                while(result.size()>0 and result.back()>s[i] and cnt[result.back()-'a']>0){
                    vis[result.back()-'a']=0;
                    result.pop_back();
                }
            result+=s[i];
            vis[s[i]-'a']=1;
            }
        }
    return result;
    }
};
