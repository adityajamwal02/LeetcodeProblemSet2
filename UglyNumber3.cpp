/*
An ugly number is a positive integer that is divisible by a, b, or c.
Given four integers n, a, b, and c, return the nth ugly number.

Example 1:
Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

Example 2:
Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.

Example 3:
Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
*/

class Solution {
public:
    long long getLCM(long long num1, long long num2){
        return (num1*num2)/__gcd(num1,num2);
    }

    int nthUglyNumber(int n, int a, int b, int c){
        long long low=1, high=INT_MAX, counter=0;
        while(low<high){
            long long mid=low+(high-low)/2;
            long long lcm1=getLCM(a,getLCM(b,c)), lcm2=getLCM(a,b), lcm3=getLCM(b,c), lcm4=getLCM(c,a);
            counter=(mid/a)+(mid/b)+(mid/c)+(mid/lcm1)-(mid/lcm2)-(mid/lcm3)-(mid/lcm4);
            if(counter<n) low=mid+1;
            else high=mid;
        }
    return (int)low;
    }
};
