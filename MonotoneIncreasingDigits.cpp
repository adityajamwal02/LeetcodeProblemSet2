/*
An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

Example 1:
Input: n = 10
Output: 9

Example 2:
Input: n = 1234
Output: 1234

Example 3:
Input: n = 332
Output: 299
*/

class Solution {
public:
    int monotoneIncreasingDigits(int n){
        string str=to_string(n);
        int i=1, j=str.size();
        while(i<j and str[i]>=str[i-1]) i++;
        if(i<j){
            while(i>0 and str[i-1]>str[i]){
                i--;
                str[i]--;
            }
        }
        for(int k=i+1;k<j;k++){
            str[k]='9';
        }
    return stoi(str);
    }
};
