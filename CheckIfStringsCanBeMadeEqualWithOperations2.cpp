/*
You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
You can apply the following operation on any of the two strings any number of times:
Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

Example 1:
Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

Example 2:
Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int n=s1.size(), m=s2.size();
        unordered_map<char,int> mp1, mp2;
        for(int i=0;i<n;i++){
            if(i%2==0) mp1[s1[i]]++;
            else mp2[s1[i]]++;
        }
        for(int i=0;i<m;i++){
            if(i%2==0){
                if(mp1.find(s2[i])==mp1.end()) return false;
                mp1[s2[i]]--;
                if(mp1[s2[i]]==0) mp1.erase(s2[i]);
            }else{
                if(mp2.find(s2[i])==mp2.end()) return false;
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0) mp2.erase(s2[i]);

            }
        }
    return true;
    }
};
