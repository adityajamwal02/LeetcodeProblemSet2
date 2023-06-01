/*
Given an integer n, return a binary string representing its representation in base -2.
Note that the returned string should not have leading zeros unless the string is "0".

Example 1:
Input: n = 2
Output: "110"
Explantion: (-2)2 + (-2)1 = 2

Example 2:
Input: n = 3
Output: "111"
Explantion: (-2)2 + (-2)1 + (-2)0 = 3

Example 3:
Input: n = 4
Output: "100"
Explantion: (-2)2 = 4
*/

class Solution {
public:
    string baseNeg2(int n) {
        if(n==0) return "0";
        string s="";
        int counter=0;
        while(n){
            if(n%2==0){
                s+='0';
            }else{
                s+='1';
                if(counter%2==1){
                    n++;
                }
            }
            counter+=1;
        n=n>>1;
        }
        reverse(s.begin(),s.end());
    return s;
    }
};
