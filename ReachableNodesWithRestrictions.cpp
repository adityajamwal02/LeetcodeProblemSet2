/*
There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.
Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
Note that node 0 will not be a restricted node.

Example 1:
Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.

Example 2:
Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
Output: 3
Explanation: The diagram above shows the tree.
We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
*/

/// Restricted nodes doesnt get added to the graph we built, then simple dfs traversal iteratively to add the counter

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted){
        unordered_set<int> set(restricted.begin(),restricted.end());
        vector<int> adj[n+1];
        for(auto edge : edges){
            int u=edge[0], v=edge[1];
            if(set.find(u)==set.end() and set.find(v)==set.end()){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        stack<int> st;
        st.push(0);
        int counter=0;
        vector<int> vis(n+1,0);
        for(auto it : set){
            vis[it]=1;
        }
        while(!st.empty()){
            auto curr=st.top();
            st.pop();
            vis[curr]=1;
            counter+=1;
            for(auto it : adj[curr]){
                if(!vis[it]){
                    st.push(it);
                }
            }
        }
    return counter;
    }
};

/// Recursive Code DFS:

class Solution {
public:
    // Recursive DFS Part
    int dfs(int node, vector<int> &vis, vector<int> adj[]){
        vis[node]=1;
        int counter=1;
        for(auto it : adj[node]){
            if(!vis[it]) counter+=dfs(it,vis,adj);
        }
    return counter;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted){
        unordered_set<int> set(restricted.begin(),restricted.end());
        vector<int> adj[n+1];
        for(auto edge : edges){
            int u=edge[0], v=edge[1];
            if(set.find(u)==set.end() and set.find(v)==set.end()){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        vector<int> vis(n+1,0);
        for(auto it : set){
            vis[it]=1;
        }

        int counter=dfs(0,vis,adj);

    return counter;
    }
};

