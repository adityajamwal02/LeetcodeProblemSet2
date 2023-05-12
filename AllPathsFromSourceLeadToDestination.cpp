/// All Paths From Source Lead To Destination


#include <bits/stdc++.h>

bool dfs(int curr, int dest, vector<int> &vis, vector<int> &recStk, vector<int> adj[]){
    if(curr==dest) return true;
    if(adj[curr].size()==0) return false;
    vis[curr]=1;
    recStk[curr]=1;
    for(auto it : adj[curr]){
        if(recStk[it]==1) return false;
        if(!vis[it] and dfs(it,dest,vis,recStk,adj)==false) return false;
    }
    recStk[curr]=0;
    return true;
}

bool leadsToDestination(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> adj[n];
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
    }
    if(adj[dest].size()!=0) return false;
    vector<int> vis(n,0), recStk(n,0);
    return dfs(src,dest,vis,recStk,adj);
}
