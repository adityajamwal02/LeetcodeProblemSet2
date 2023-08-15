/*
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

Example 1:
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).

Example 2:
Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.

Example 3:
Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
*/

/// (BFS/DFS) + Binary Search


class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    bool isValid(int i, int j, int n, int m){
        if(i>=0 and j>=0 and i<n and j<m) return true;
    return false;
    }

    bool dfs(int i, int j, int n, int m, int mid, vector<vector<int>> &dist, vector<vector<int>> &vis){
        if(dist[i][j]<mid) return false;
        if(i==n-1 and j==m-1) return true;
        bool flag=false;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(isValid(nrow,ncol,n,m) and !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                flag=flag|dfs(nrow,ncol,n,m,mid,dist,vis);
                if(flag) return true;
            }
        }
    return flag;
    }

    void getManhattanDistance(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dist, int &maxPossible){
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(isValid(nrow,ncol,n,m) and (dist[nrow][ncol]>1+dist[i][j])){
                    dist[nrow][ncol]=1+dist[i][j];
                    q.push({nrow,ncol});
                    maxPossible=max(maxPossible,dist[nrow][ncol]);
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(), maxPossible=0;
        if(grid[0][0]==1) return 0;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        getManhattanDistance(n,n,grid,dist,maxPossible);
        int low=0, high=maxPossible, result=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            vector<vector<int>> vis(n,vector<int>(n));
            if(dfs(0,0,n,n,mid,dist,vis)){
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return result;
    }
};
