/// Problem Code: SNSOCIAL : Codechef

/// Multisource BFS

#include <bits/stdc++.h>
using namespace std;

int delrow[8]={-1,-1,-1,0,0,1,1,1};
int delcol[8]={-1,0,1,-1,1,-1,0,1};

bool isValid(int nrow, int ncol, int n, int m){
    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m) return true;

return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    vector<vector<int>> grid(n,vector<int>(m));
	    int maxi=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>grid[i][j];
	            maxi=max(maxi,grid[i][j]);
	        }
	    }

	    vector<vector<int>> vis(n,vector<int>(m,0));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==maxi){
	                q.push({i,j});
	                vis[i][j]=1;
	            }
	        }
	    }

	    while(!q.empty()){
	        int i = q.front().first;
	        int j = q.front().second;
	        q.pop();
	        for(int k=0;k<8;k++){
	            int nrow=i+delrow[k];
	            int ncol=j+delcol[k];
	            if(isValid(nrow,ncol,n,m) and vis[nrow][ncol]==0){
	                vis[nrow][ncol]=vis[i][j]+1;
	                q.push({nrow,ncol});
	            }

	        }
	    }

	    int maxTime=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            maxTime=max(maxTime,vis[i][j]);
	        }
	    }

	    cout<<maxTime-1<<endl;
	}
	return 0;
}

