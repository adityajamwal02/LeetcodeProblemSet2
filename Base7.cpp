/*
Given an integer num, return a string of its base 7 representation.

Example 1:
Input: num = 100
Output: "202"

Example 2:
Input: num = -7
Output: "-10"
*/

class Solution {
public:
    string s="";
    string convertToBase7(int num, bool flag=0) {
       if(num==0){
           if(s.size()==0) return "0";
           else reverse(s.begin(),s.end());
        return flag ? "-"+s : s;
       }
       if(num<0) flag=1;
       s.push_back(abs(num)%7+'0');
    return convertToBase7(abs(num)/7,flag);
    }
};
