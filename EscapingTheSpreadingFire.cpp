/*
You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
0 represents grass,
1 represents fire,
2 represents a wall that you and fire cannot pass through.
You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

Example 1:
Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
Output: 3
Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
You will still be able to safely reach the safehouse.
Staying for more than 3 minutes will not allow you to safely reach the safehouse.

Example 2:
Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
Output: -1
Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
Thus, -1 is returned.

Example 3:
Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
Output: 1000000000
Explanation: The figure above shows the initial grid.
Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
Thus, 109 is returned.
*/


/// BFS (2 queue: Fire and Person) + Binary Search

class Solution {
public:

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    bool isCheck(int mid, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dist){
        queue<pair<int,int>> q;         // BFS state w.r.t person
        int counter=1;
        vector<vector<int>> dist1(n,vector<int>(m,-1));
        q.push({0,0});
        dist1[0][0]=0;                   // source -> 0,0
        // 4 directional person path
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it.first==n-1 and it.second==m-1) return true;
            for(int i=0;i<4;i++){
                int nrow=it.first+delrow[i];
                int ncol=it.second+delcol[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==0 and dist1[nrow][ncol]==-1
                        and dist[nrow][ncol]>1+dist1[it.first][it.second]+mid){
                    q.push({nrow,ncol});
                    dist1[nrow][ncol]=dist1[it.first][it.second]+1;
                }else if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==0 and dist1[nrow][ncol]==-1
                        and nrow==n-1 and ncol==m-1 and dist[nrow][ncol]==1+dist1[it.first][it.second]+mid){
                    q.push({nrow,ncol});
                    dist1[nrow][ncol]=dist1[it.first][it.second]+1;
                }
            }
        }
    return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;      // fire spread scenario
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));     // Fire Approach
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        // 4 directional fire spread
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=it.first+delrow[i];
                int ncol=it.second+delcol[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==0 and dist[nrow][ncol]==INT_MAX){
                    q.push({nrow,ncol});
                    dist[nrow][ncol]=dist[it.first][it.second]+1;
                }
            }
        }
        // Binary Search
        int low=0, high=1e9, result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isCheck(mid,grid,n,m,dist)){           // Check for position of person w.r.t fire
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return result;
    }
};


