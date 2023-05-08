/*
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.
If the path is not possible between source cell and destination cell, then return -1.
Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing.

Example 1:
Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the
shortest path from source to destination cell.

Example 2:
Input:
grid[][] = {{1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1}}
source = {0, 0}
destination = {3, 4}
Output:
-1
Explanation:
The path is not possible between source and
destination, hence return -1.
Your Task:

You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
*/


// User function Template for C++

class Solution {
  public:

    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    bool isValid(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i>=0 and j>=0 and i<n and j<m and grid[i][j]==1){
            return true;
        }
    return false;
    }

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n=grid.size(), m=grid[0].size();
        if(grid[source.first][source.second]==0) return -1;
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        distance[source.first][source.second]=0;
        queue<pair<int, pair<int,int>> >q;
        q.push({0,{source.first,source.second}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first, row=it.second.first, col=it.second.second;
            if(row==destination.first and col==destination.second) return dis;
            for(int i=0;i<8;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(isValid(nrow,ncol,n,m,grid) and dis+1<distance[nrow][ncol]){
                    distance[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
    return -1;
    }
};
