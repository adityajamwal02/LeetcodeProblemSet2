/*
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars){
        vector<char> mp(26,0);
        for(char ch : chars){
            mp[ch-'a'] +=1;
        }
        int flag, result=0;
        for(string word : words){
            if(word.length()>chars.length()) continue;
            vector<char> temp(26,0);
            flag=1;
            for(char ch : word) temp[ch-'a']+=1;
            for(char ch : word){
                if(mp[ch - 'a']<temp[ch-'a']){
                    flag=0;
                    break;
                }
            }
            if(flag) result+=word.length();
        }
    return result;
    }
};
