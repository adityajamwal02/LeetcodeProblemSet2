/*
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

Example 1:
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

Example 2:
Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
*/

class Solution {
public:
    int helper(int i, int j, int row2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        int n=grid.size();
        int col2=i+j-row2;
        if(i>=n or j>=n or row2>=n or col2>=n) return INT_MIN;
        if(grid[i][j]==-1 or grid[row2][col2]==-1) return INT_MIN;
        if(i==n-1 and j==n-1) return grid[n-1][n-1];
        if(dp[i][j][row2]!=INT_MIN){
            return dp[i][j][row2];
        }
        int ans;
        if(i==row2 and j==col2){
            ans=grid[i][j];
        }else{
            ans=grid[i][j]+grid[row2][col2];
        }
        ans+=max({helper(i+1,j,row2+1,grid,dp), helper(i,j+1,row2,grid,dp), helper(i+1,j,row2,grid,dp), helper(i,j+1,row2+1,grid,dp)});
    return dp[i][j][row2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
    return max(0,helper(0,0,0,grid,dp));
    }
};
