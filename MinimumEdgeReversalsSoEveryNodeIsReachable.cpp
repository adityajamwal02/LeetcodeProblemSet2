/*
There is a simple directed graph with n nodes labeled from 0 to n - 1. The graph would form a tree if its edges were bi-directional.
You are given an integer n and a 2D integer array edges, where edges[i] = [ui, vi] represents a directed edge going from node ui to node vi.
An edge reversal changes the direction of an edge, i.e., a directed edge going from node ui to node vi becomes a directed edge going from node vi to node ui.
For every node i in the range [0, n - 1], your task is to independently calculate the minimum number of edge reversals required so it is possible to reach any other node starting from node i through a sequence of directed edges.
Return an integer array answer, where answer[i] is the minimum number of edge reversals required so it is possible to reach any other node starting from node i through a sequence of directed edges.

Example 1:
Input: n = 4, edges = [[2,0],[2,1],[1,3]]
Output: [1,1,0,2]
Explanation: The image above shows the graph formed by the edges.
For node 0: after reversing the edge [2,0], it is possible to reach any other node starting from node 0.
So, answer[0] = 1.
For node 1: after reversing the edge [2,1], it is possible to reach any other node starting from node 1.
So, answer[1] = 1.
For node 2: it is already possible to reach any other node starting from node 2.
So, answer[2] = 0.
For node 3: after reversing the edges [1,3] and [2,1], it is possible to reach any other node starting from node 3.
So, answer[3] = 2.

Example 2:
Input: n = 3, edges = [[1,2],[2,0]]
Output: [2,0,1]
Explanation: The image above shows the graph formed by the edges.
For node 0: after reversing the edges [2,0] and [1,2], it is possible to reach any other node starting from node 0.
So, answer[0] = 2.
For node 1: it is already possible to reach any other node starting from node 1.
So, answer[1] = 0.
For node 2: after reversing the edge [1, 2], it is possible to reach any other node starting from node 2.
So, answer[2] = 1.
*/


class Solution {
public:

    int dfs(int node, int n, unordered_map<int,unordered_set<int>> &adjUD, unordered_map<int,unordered_set<int>> &adjD, vector<bool> &vis){
        int counter=0;
        vis[node]=true;
        for(auto it : adjUD[node]){
            if(!vis[it]){
                if(adjD[node].empty() or adjD[node].find(it)==adjD[node].end()) counter++;
            counter+=dfs(it,n,adjUD,adjD,vis);
            }
        }
    return counter;
    }

    void bfs(int n, queue<pair<int,int>> &q, vector<int> &result, unordered_map<int, unordered_set<int>> &adjUD, unordered_map<int, unordered_set<int>>&adjD){
        while(!q.empty()){
            int sz=q.size();
            queue<pair<int,int>> newQ;
            for(int i=0;i<sz;i++){
                int node=q.front().first, parent=q.front().second;
                q.pop();
                if(result[node]==-1){
                    result[node]=(adjD[node].find(parent)!=adjD[node].end()) ? result[parent]-1 : result[parent]+1;
                    for(auto neighbour : adjUD[node]) newQ.push({neighbour,node});
                }
            }
            q=newQ;
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges){
        vector<int> result(n,-1);
        unordered_map<int, unordered_set<int>> adjD, adjUD;
        queue<pair<int,int>> q;
        vector<bool> vis(n,false);

        for(auto edge : edges){
            int u=edge[0], v=edge[1];
            if(adjUD.find(u)==adjUD.end()) adjUD[u]=unordered_set<int>();
            if(adjUD.find(v)==adjUD.end()) adjUD[v]=unordered_set<int>();
            adjUD[u].insert(v);
            adjUD[v].insert(u);

            if(adjD.find(u)==adjD.end()) adjD[u]=unordered_set<int>();
            adjD[u].insert(v);
        }

        result[0]=dfs(0,n,adjUD,adjD,vis);

        for(auto nodes : adjUD[0]) q.push({nodes,0});

        bfs(n,q,result,adjUD,adjD);

    return result;
    }
};
