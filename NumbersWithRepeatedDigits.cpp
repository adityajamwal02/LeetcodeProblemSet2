/*
Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.

Example 1:
Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.

Example 2:
Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.

Example 3:
Input: n = 1000
Output: 262
*/

class Solution {
public:
    int dp[10][2][1<<10][2][2];

    int helper(int i, int tight, int mask, int repeat, int zero, string &str, int n){
        if(i==n) return (repeat==1 and zero==1);
        if(dp[i][tight][mask][repeat][zero]!=-1) return dp[i][tight][mask][repeat][zero];
        int result=0;
        int limit=(tight ? str[i]-'0' : 9);
        for(int j=0;j<=limit;j++){
            int newTight=(tight and j==limit);
            int newZero=(zero or (j!=0));
            int newMask=mask, newRepeat=0;
            if(newZero!=0) newMask=(mask|(1<<j));
            if(newZero!=0) newRepeat=(repeat or (mask&(1<<j)));
            result+=helper(i+1,newTight,newMask,newRepeat,newZero,str,n);
        }
    return dp[i][tight][mask][repeat][zero]=result;
    }

    int numDupDigitsAtMostN(int n){
        string str=to_string(n);
        n=str.size();
        memset(dp,-1,sizeof(dp));

    return helper(0,1,0,0,0,str,n);
    }
};
