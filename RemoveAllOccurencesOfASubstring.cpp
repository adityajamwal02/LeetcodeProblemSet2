/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
A substring is a contiguous sequence of characters in a string.

Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

Example 2:
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

*/

/// Using npos

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // npos: special variable in string which means the substring which we are finding is not present there.
        int occur=s.find(aprt);
        while(occur!=string::npos){
            s.erase(occur,part.size());
            occur=s.find(part);
        }
    return s;
    }
};

/// Similar to above code but conceptually rather than using npos

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.size()!=0 and s.find(part)<s.size()){
            s.erase(s.find(part),part.size());
        }
       return s;
    }
};
