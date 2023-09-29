/*
You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

Example 1:
example 1
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.

Example 2:
Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".

Example 3:
Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.
*/

class Solution {
public:
    bool find(string s, int n, string temp, int k){
        int counter=0, j=0;
        for(int i=0;i<n;i++){
            if(s[i]==temp[j]){
                j++;
                if(j==temp.size()){
                    counter++;
                    j=0;
                }
                if(counter==k) return true;
            }
        }
    return false;
    }

    string longestSubsequenceRepeatedK(string s, int k){
        int n=s.size();
        string result="";
        queue<string> q;
        q.push("");
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(int i=0;i<26;i++){
                string temp=curr+char('a'+i);
                if(find(s,n,temp,k)){
                    result=temp;
                    q.push(temp);
                }
            }
        }
    return result;
    }
};
