/*
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].
Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

Example 1:
Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".

Example 2:
Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.

Example 3:
Input: s1 = "xx", s2 = "xy"
Output: -1
*/

class Solution {
public:
    int minimumSwap(string s1, string s2){
        int n=s1.size(), m=s2.size(), xy=0, yx=0, result=0;
        if(n!=m) return -1;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            else if(s1[i]=='x') xy++;
            else if(s1[i]=='y') yx++;
        }
        if((xy+yx)%2) return -1;
        result=xy/2+yx/2;
        if(xy%2) result+=2;
    return result;
    }
};
