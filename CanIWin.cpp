/*
In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

Example 1:
Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

Example 2:
Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true

Example 3:
Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true
*/


class Solution {
public:
    int n, k, sum=0;
    unordered_map<long long, bool> mp;

    bool helper(long long currSet, int currSum){
        if(currSum>=k) return false;
        long long it=currSet;
        if(mp.count(it)) return mp[it];
        for(int i=1;i<=n;i++){
            int mask=1<<i;
            if((currSet&mask)==0){
                if(!helper((currSet|mask),currSum+i)) return mp[it]=true;
            }
        }
    return mp[it]=false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal){
        n=maxChoosableInteger, k=desiredTotal;
        for(int i=1;i<=n;i++) sum+=i;
        if(sum<k) return false;
        if(k<=0) return true;

    return helper(0,0);
    }
};
