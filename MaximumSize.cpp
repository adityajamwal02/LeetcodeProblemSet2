/// Maximum Size: Codechef question: Problem Code: RISK

#include <bits/stdc++.h>
using namespace std;

int delrow[4]={-1,0,1,0};
int delcol[4]={0,-1,0,1};
int counter=0;

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
    int n=grid.size(), m=grid[0].size();
    vis[i][j]=1;
    counter++;
    for(int k=0;k<4;k++){
        int nrow=i+delrow[k];
        int ncol=j+delcol[k];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and vis[nrow][ncol]==0){
            dfs(nrow,ncol,grid,vis);
        }
    }
}

int captureLands(int n, int m, vector<vector<char>> &grid){
    vector<vector<int>> vis(n,vector<int>(m,0));
    int result=0;
    vector<int> vec;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' and !vis[i][j]){
                dfs(i,j,grid,vis);
                vec.push_back(counter);
                counter=0;
            }
        }
    }
    sort(vec.rbegin(),vec.rend());
    for(int i=0;i<vec.size();i++){
        if(i%2==1) result+=vec[i];
    }
    return result;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<char>> grid(n,vector<char>(m,'0'));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>grid[i][j];
	        }
	    }
	    int ans=captureLands(n,m,grid);
	    cout<<ans<<endl;
	}
	return 0;
}
