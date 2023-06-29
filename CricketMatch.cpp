///  Cricket Match : Problem Code: CRIMCH

#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int node, int n, vector<int> &vis, vector<int> adj[]){
    queue<int> q;
    q.push(node);
    vis[node]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto adjNode : adj[curr]){
            if(vis[adjNode]<0){
                vis[adjNode]=vis[curr]+1;
                q.push(adjNode);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(vis[i]<0) continue;
        for(int v : adj[i]){
            if(vis[i]%2==vis[v]%2) return false;
        }
    }
    return true;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<int> adj[n];
	    int u,v,i;
	    for(int i=0;i<m;i++){
	        cin>>u>>v;
	        adj[u-1].push_back(v-1);
	        adj[v-1].push_back(u-1);
	    }
	    vector<int> vis(n,-1);
	    for(i=0;i<n;i++){
	        if(vis[i]<0 and !isBipartite(i,n,vis,adj)) break;
	    }
	    if(i==n) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
}
