/*
Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.

Example 1:
Input: n = 5
Output: 2
Explanation: 5 = 2 + 3

Example 2:
Input: n = 9
Output: 3
Explanation: 9 = 4 + 5 = 2 + 3 + 4

Example 3:
Input: n = 15
Output: 4
Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
*/

/// IDEA : for x natural numbers -> sum : x(x+1)/2;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // for x integers : x*(x+1)/2 ; 1,2,3,4....x
        // n >= x*x(x+1)/2 and (n - (x*(x+1)/2))%x==0)
        int result=0;
        for(int x=1;x*(x+1)/2<=n;x++){
            int value=x*(x+1)/2;
            if((n-value)%x==0) result++;
        }
    return result;
    }
};
