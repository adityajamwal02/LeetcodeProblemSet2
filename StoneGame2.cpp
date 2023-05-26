/*
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones.
Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger.

Example 2:
Input: piles = [1,2,3,4,5,100]
Output: 104
*/


class Solution {
public:
    int solve(vector<int> &piles, int i, int m, bool score, vector<vector<vector<int>>> &dp){
        if(i==piles.size()) return 0;
        if(score){
            if(dp[i][1][m]!=-1) return dp[i][1][m];
        }else if(dp[i][0][m]!=-1) return dp[i][0][m];
        int result=0;
        if(score) result=0;
        else result=INT_MAX;
        int total=0;
        for(int x=1;x<=2*m;x++){
            if(i+x>piles.size()) break;
            total+=piles[i+x-1];
            if(score) result=max(result,total+solve(piles,i+x,max(m,x),!score,dp));
            else result=min(result,solve(piles,i+x,max(m,x),!score,dp));
        }
        if(score) dp[i][1][m]=result;
        else dp[i][0][m]=result;
    return result;
    }
    int stoneGameII(vector<int>& piles) {
        if(piles.size()==1) return piles[0];
        int n=piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(n*2,-1)));
    return solve(piles,0,1,true,dp);
    }
};
