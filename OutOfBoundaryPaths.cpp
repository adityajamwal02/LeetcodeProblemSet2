/*
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
*/


class Solution {
public:
    int mod=1e9+7;
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    long long dp[51][51][51];

    long long helper(int i, int j, int k, int m, int n){
        if(k<0) return 0;
        if(i<0 or j<0 or i>=m or j>=n) return 1;
        long long result=0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        for(int t=0;t<4;t++){
            long long nrow=i+delrow[t];
            long long ncol=j+delcol[t];
            result=(result%mod+helper(nrow,ncol,k-1,m,n)%mod)%mod;
        }
    return dp[i][j][k]=result%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
        memset(dp,-1,sizeof(dp));
        int result=(int)helper(startRow,startColumn,maxMove,m,n);    // i-> row, j-> col, k->steps(moves)
    return result;
    }
};
