/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

Example 3:
Input: s = "abc"
Output: 1
*/

class Solution {
public:
    int helper(string s, int k){
        int i=0, j=0, n=s.size(), counter=0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()>k){
                while(i<=j and mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            counter+=(j-i+1);
        j++;
        }
    return counter;
    }
    int numberOfSubstrings(string s) {
        return helper(s,3)-helper(s,2);
    }
};
