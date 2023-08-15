/// Coding ninjas

#include <bits/stdc++.h>
using namespace std;

int delrow[4]={-1,0,1,0};
int delcol[4]={0,-1,0,1};

int dfs(int i, int j, int rowEnd, int colEnd, int n, int m, vector<vector<int>> &mat){
	if(i==rowEnd and j==colEnd) return 0;
	int result=INT_MIN;
	mat[i][j]=-1;
	for(int k=0;k<4;k++){
		int nrow=i+delrow[k];
		int ncol=j+delcol[k];
		if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and mat[nrow][ncol]==1){
			int dist=1+dfs(nrow,ncol,rowEnd,colEnd,n,m,mat);
			result=max(result,dist);
		}
	}
	mat[i][j]=1;
return result;
}

int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy) {
	int result=-1;
	if(mat[sx][sy]){
		result=dfs(sx,sy,dx,dy,n,m,mat);
	}
return result;
}

