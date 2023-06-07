/*
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

Example 1:
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:
Input: a = 4, b = 2, c = 7
Output: 1

Example 3:
Input: a = 1, b = 2, c = 3
Output: 0
*/

/// Solution simple logic

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int counter=0;
        while(a or b or c){
            int x=a&1, y=b&1, z=c&1;
            if((x|y)!=z){
                if(x&y){
                    counter+=2;
                }else{
                    counter+=1;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
    return counter;
    }
};

/// Recursive

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int mask=a|b;
        if(mask==c or (a==0 and b==0 and c==0)) return 0;
        if((c&1)==0){
            if((a&1)&(b&1)) return minFlips(a>>1,b>>1,c>>1)+2;
        }
    return (((a&1)|(b&1))==(c&1)) ? minFlips(a>>1,b>>1,c>>1) : minFlips(a>>1,b>>1,c>>1)+1;
    }
};
