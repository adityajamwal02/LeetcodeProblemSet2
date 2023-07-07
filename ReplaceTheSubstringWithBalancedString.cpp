/*
You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.

Example 1:
Input: s = "QWER"
Output: 0
Explanation: s is already balanced.

Example 2:
Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.

Example 3:
Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER".
*/

class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        int k=n/4, result=s.size();
        unordered_map<char,int>mp;
        /// Marking the count of all those characters frequency who are greater than k
        for(auto ch : s){
            mp[ch]++;
        }
        int i=0, j=0;
        /// Minimum Window Substring on
        while(j<n){
            mp[s[j]]--;
            while(i<n and mp['W']<=k and mp['Q']<=k and mp['E']<=k and mp['R']<=k){
                result=min(result,j-i+1);
                mp[s[i]]++;
                i++;
            }
        j++;
        }
    return result;
    }
};
