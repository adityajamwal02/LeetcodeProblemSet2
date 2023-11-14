/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
A palindrome is a string that reads the same forwards and backwards.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
*/

class Solution {
public:
    int countPalindromicSubsequence(string s){
        int result=0, n=s.size();
        unordered_set<char> st1, st2;
        for(char ch : s){
            st1.insert(ch);
        }
        for(char ch : st1){
            int curr=0, prev=-1;
            for(int i=0;i<n;i++){
                if(s[i]==ch){
                    if(prev==-1) prev=i;
                    curr=i;
                }
            }
            for(int i=prev+1;i<curr;i++){
                st2.insert(s[i]);
            }
            result+=st2.size();
        st2.clear();
        }
    return result;
    }
};
