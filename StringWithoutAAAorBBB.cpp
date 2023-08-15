/*
Given two integers a and b, return any string s such that:
s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
The substring 'aaa' does not occur in s, and
The substring 'bbb' does not occur in s.

Example 1:
Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.

Example 2:
Input: a = 4, b = 1
Output: "aabaa"
*/

class Solution {
public:
    string helper(int a, int b, char ch1, char ch2){
        string result="";
        int counter=0;
        while(a>0 or b>0){
            if(a>0){
                result+=ch1;
                a--;
                if(a>b){
                    result+=ch1;
                    a--;
                }
            }
            if(b>0){
                result+=ch2;
                b--;
            }
        }
    return result;
    }

    string strWithout3a3b(int a, int b) {
        int countA=a, countB=b;
    return (a>=b) ? helper(countA,countB,'a','b') : helper(countB,countA,'b','a');
    }
};
