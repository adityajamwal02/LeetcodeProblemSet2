/*
Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
The Fibonacci numbers are defined as:
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 for n > 2.
It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.

Example 1:
Input: k = 7
Output: 2
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ...
For k = 7 we can use 2 + 5 = 7.

Example 2:
Input: k = 10
Output: 2
Explanation: For k = 10 we can use 2 + 8 = 10.

Example 3:
Input: k = 19
Output: 3
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
*/

class Solution {
public:
    vector<long long> dp;

    void fibonacci(int n){
        dp.resize(n);
        dp[0]=dp[1]=1;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
    }

    int findMinFibonacciNumbers(int k){
        fibonacci(50);
        int counter=0;
        while(k>0){
            auto curr=lower_bound(dp.begin(),dp.end(),k);
            if(*curr!=k){
                curr--;
            }
            k-=*curr;
        counter++;
        }
    return counter;
    }
};
