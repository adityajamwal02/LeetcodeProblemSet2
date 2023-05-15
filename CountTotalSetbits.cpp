/*
You are given a number N. Find the total number of setbits in the numbers from 1 to N.

Example 1:
Input: N = 3
Output: 4
Explaination:
1 -> 01, 2 -> 10 and 3 -> 11.
So total 4 setbits.

Example 2:
Input: N = 4
Output: 5
Explaination: 1 -> 01, 2 -> 10, 3 -> 11
and 4 -> 100. So total 5 setbits.
Your Task:
You do not need to read input or print anything. Your task is to complete the function countBits() which takes N as input parameter and returns the total number of setbits upto N.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/


/// Using builtin popcount


class Solution {
  public:
    long long countBits(long long N) {
        long long result=0;
        for(int i=1;i<=N;i++){
            result+=__builtin_popcount(i);
        }
    return result;
    }
};


/// Most Optimized Solution

long long countBits(long long N) {
        long long ans = 0;
        int num2 = 2;
        for(int i = 0; i < 31; i++){
            ans += (N / num2) * (num2>>1);
            if(((N % num2) - (num2>>1) + 1) > 0)
                ans += ((N % num2) - (num2>>1) + 1);
            if (num2 > N) {
                break;
            }
            num2 <<= 1;
        }
        return ans;
    }
