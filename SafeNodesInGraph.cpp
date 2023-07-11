/// Safe Nodes in Graph : Topological Sort Problem


#include <bits/stdc++.h>
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<int> adjRev[n];
    vector<int> result, indegree(n,0);
    for(int i=0;i<e;i++){
        int u=edges[i][0], v=edges[i][1];
        adjRev[v].push_back(u);
        indegree[u]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        result.push_back(node);
        for(auto it : adjRev[node]){
            indegree[it]--;
            if (indegree[it] == 0) {
              q.push(it);
            }
        }
    }
    sort(result.begin(),result.end());
    return result;
}
