/*
You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
You can apply the following operation on any of the two strings any number of times:
Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

Example 1:
Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: We can do the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
- Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.

Example 2:
Input: s1 = "abcd", s2 = "dacb"
Output: false
Explanation: It is not possible to make the two strings equal.
*/


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n=s1.size();
        if(s1==s2) return true;
        bool check1=((s1[2]==s2[2] and s1[0]==s2[0]) or (s1[0]==s2[2] and s1[2]==s2[0]));
        bool check2=((s1[1]==s2[1] and s1[3]==s2[3]) or (s1[1]==s2[3] and s1[3]==s2[1]));
    return check1 and check2;
    }
};
