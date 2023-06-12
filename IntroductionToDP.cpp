/*
Geek is learning data structures, and he recently learned about the top-down an bottom-up dynamic programming approaches. Geek is having trouble telling them apart from one another.
When given an integer n, where n is based on a 0-based index, find the nth Fibonacci number.
Every ith number in the series equals the sum of the (i-1)th and (i-2)th numbers, where the first and second numbers are specified as 0 and 1, respectively.
For the given issue, code both top-down and bottom-up approaches.
As the answer might be large, return the final answer modulo 109 + 7

Example 1:
Input:
n = 5
Output: 5
Explanation: 0,1,1,2,3,5 as we can see 5th number is 5.

Example 2:
Input:
n = 6
Output: 8
Explanation: 0,1,1,2,3,5,8 as we can see 6th number is 8.
Constraints:
1 <= n <= 1000

Your Task:
You don't need to read input or print anything. Your task is to complete two functions topDown() and bottomUp() which takes n as input parameters and returns the nth Fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/


int mod=1e9+7;

class Solution {
  public:
    long long helper(int n, vector<long long> &dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(helper(n-1,dp)+helper(n-2,dp))%mod;
    }
    long long int topDown(int n) {
        vector<long long> dp(n+1,-1);
    return helper(n,dp);
    }
    long long int bottomUp(int n) {
        vector<long long> dp2(n+1,0);
        dp2[0]=0;
        dp2[1]=1;
        for(int i=2;i<=n;i++){
            dp2[i]=(dp2[i-1]+dp2[i-2])%mod;
        }
    return dp2[n];
    }
};
