/*
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.
A good string is a string constructed by the above process having a length between low and high (inclusive).
Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

Example 1:
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.

Example 2:
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".

Constraints:
1 <= low <= high <= 105
1 <= zero, one <= low
*/

/// Recursive

class Solution {
public:
    int mod=1e9+7;
    int helper(int len, int low, int high, int zero, int one){
        if(len>high) return 0;
        int counter=0;
        if(len>= low and len<=high){
            counter=1;
        }
        counter+=helper(len+zero,low,high,zero,one)%mod;
        counter%=mod;
        counter+=helper(len+one,low,high,zero,one)%mod;

    return counter;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        return helper(0,low,high,zero,one);
    }
};

/// Memoization

class Solution {
public:
    int mod=1e9+7;
    int helper(int len, int low, int high, int zero, int one, vector<int> &dp){
        if(len>high) return 0;
        if(dp[len]!=-1) return dp[len];
        int counter=0;
        if(len>= low and len<=high){
            counter=1;
        }
        counter+=helper(len+zero,low,high,zero,one,dp)%mod;
        counter%=mod;
        counter+=helper(len+one,low,high,zero,one,dp)%mod;
        dp[len]=counter;
    return counter%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return helper(0,low,high,zero,one,dp);
    }
};

/// Tabulation


