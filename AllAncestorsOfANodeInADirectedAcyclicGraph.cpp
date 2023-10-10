/*
You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).
You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.
Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.
A node u is an ancestor of another node v if u can reach v via a set of edges.

Example 1:
Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.

Example 2:
Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
*/


/// BFS

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
        vector<vector<int>> ans(n);
        vector<int> adj[n+1];
        for(auto edge : edges){
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            vector<bool> vis(n,0);
            vis[i]=1;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int curr=q.front();
                q.pop();
                for(auto it :adj[curr]){
                    if(!vis[it]){
                        vis[it]=1;
                        ans[i].push_back(it);
                        q.push(it);
                    }
                }
            }
        }
        for(auto&a:ans)
            sort(a.begin(),a.end());

    return ans;
    }
};

/// DFS

class Solution {
public:
    void dfs(int node, vector<int> &temp, vector<int> &vis, vector<int> adj[]){
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                temp.push_back(it);
                dfs(it,temp,vis,adj);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
        vector<vector<int>> result;
        vector<int> adj[n+1];
        vector<int> temp;
        for(auto edge : edges){
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(i,temp,vis,adj);
            sort(temp.begin(),temp.end());
            result.push_back(temp);
            temp.clear();
        }
    return result;
    }
};
