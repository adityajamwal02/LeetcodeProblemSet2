/*
You are given a 0-indexed m x n matrix grid consisting of positive integers.
You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

Example 1:
Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.

Example 2:
Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any moves.
*/

class Solution {
public:

    int recursiveMaxMoves(std::vector<std::vector<int>>& grid, int row, int col, int prevValue, vector<vector<int>>& dp) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] <= prevValue) {
            return 0;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int maxMoves = 0;
        maxMoves = max(maxMoves, recursiveMaxMoves(grid, row - 1, col + 1, grid[row][col],dp));
        maxMoves = max(maxMoves, recursiveMaxMoves(grid, row, col + 1, grid[row][col],dp));
        maxMoves = max(maxMoves, recursiveMaxMoves(grid, row + 1, col + 1, grid[row][col],dp));
        dp[row][col] = maxMoves + 1;
        return dp[row][col];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        vector<vector<int>> dp(m, std::vector<int>(n, -1));
        int maxMoves = 0;
        for (int i = 0; i < m; i++) {
            maxMoves = max(maxMoves, recursiveMaxMoves(grid, i, 0, 0, dp));
        }
        return maxMoves-1;
    }

};
