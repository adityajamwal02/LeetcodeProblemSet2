/*
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

Example 1:
Input: piles = [5,3,4,5]
Output: true
Explanation:
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.

Example 2:
Input: piles = [3,7,2,3]
Output: true
*/

/// Simple (one after another)

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int a,b;
        int n=piles.size()-1;
        for(int i=0;i<n;i++){
            if(i%2==0 and piles[i]>piles[n-i]){
                a+=piles[i];
            }else if(i%2==0 and piles[i]<piles[n-i]){
                a+=piles[n-i];
            }else if(i%2==1 and piles[i]>piles[n-i]){
                b+=piles[i];
            }else if(i%2==1 and piles[i]<piles[n-i]){
                b+=piles[n-i];
            }
        }
    if(a>b) return true;
    return false;
    }
};

/// DP Solution


class Solution {
public:
    bool helper(int i, vector<int> &piles, vector<int> &dp){
        if(i<0) return false;
        if(i==0) return piles[i];
        if(dp[i]!=-1) return dp[i];
        int take=piles[i]+helper(i-1,piles,dp);
        int notTake=helper(i-2,piles,dp);
    return dp[i]=max(take,notTake);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<int> dp(n,-1);
    return max(helper(n-1,piles,dp),helper(0,piles,dp));
    }
};
