
#include <bits/stdc++.h>
int delrow[8]={-1,-1,-1,0,0,1,1,1};
int delcol[8] = {-1,0,1,1,-1,-1,0,1};
void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, int &curr){
    curr++;
    vis[i][j]=1;
    for(int k=0;k<8;k++){
        int nrow=i+delrow[k];
        int ncol=j+delcol[k];
        if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1 and !vis[nrow][ncol]){
            dfs(nrow,ncol,n,m,grid,vis,curr);
        }
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid, int n, int m) {
    int maxVal=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] and grid[i][j]==1){
                int curr=0;
                dfs(i,j,n,m,grid,vis,curr);
                maxVal=max(maxVal,curr);
            }
        }
    }
    return maxVal;
}
