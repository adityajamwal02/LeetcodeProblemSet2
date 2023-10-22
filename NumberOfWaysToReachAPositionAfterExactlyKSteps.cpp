/*
You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.
Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.
Two ways are considered different if the order of the steps made is not exactly the same.
Note that the number line includes negative integers.

Example 1:
Input: startPos = 1, endPos = 2, k = 3
Output: 3
Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
It can be proven that no other way is possible, so we return 3.

Example 2:
Input: startPos = 2, endPos = 5, k = 10
Output: 0
Explanation: It is impossible to reach position 5 from position 2 in exactly 10 steps.
*/

class Solution {
public:
    const long int mod=1e9+7;
    long long dp[3001][3001];

    long long helper(int start, int end, int k){
        if(k==0){
            if(start==end) return 1;
        return 0;
        }
        if(k<=0) return 0;
        if(dp[start+1000][k]!=-1) return dp[start+1000][k];

    return dp[start+1000][k]=(helper(start+1,end,k-1)%mod+helper(start-1,end,k-1)%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k){
        memset(dp,-1,sizeof(dp));
        if(abs(startPos-endPos)>k) return 0;
        long long result=helper(startPos,endPos,k);
    return result;
    }
};
