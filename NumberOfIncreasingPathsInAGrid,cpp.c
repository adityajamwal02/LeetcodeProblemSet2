/*
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.
Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.
Two paths are considered different if they do not have exactly the same sequence of visited cells.

Example 1:
Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

Example 2:
Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.
*/

/// DFS + DP

class Solution {
public:
    int mod=1e9+7;
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    int dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]>grid[i][j]){
                ans=(ans%mod + dfs(nrow,ncol,n,m,grid,dp)%mod)%mod;
            }
        }
        return dp[i][j]=ans%mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        long long counter=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                counter=(counter%mod + dfs(i,j,n,m,grid,dp)%mod)%mod;
            }
        }
    return (int)counter%mod;
    }
};
};
