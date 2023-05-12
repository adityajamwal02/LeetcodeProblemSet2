/*
Given a graph which represents a flow network with N vertices numbered 1 to N and M edges.Find the maximum flow from vertex numbered 1 to vertex numbered N.
In a flow network,every edge has a flow capacity and the maximum flow of a path can't exceed the flow-capacity of an edge in the path.

Example 1:
Input:
N = 5, M =  4
Edges[]= {{1,2,1},{3,2,2},{4,2,3},{2,5,5}}
Output: 1
Explanation:
1 - 2 - 3
   / \
  4   5
1 unit can flow from 1 -> 2 - >5

Example 2:
Input:
N = 4, M = 4
Edges[] = {{1,2,8},{1,3,10},{4,2,2},{3,4,3}}
Output: 5
Explanation:
  1 - 2
  |   |
  3 - 4
3 unit can flow from 1 -> 3 -> 4
2 unit can flow from 1 -> 2 -> 4
Total max flow from 1 to N = 3+2=5
Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes the N (the number of vertices) ,M (the number of Edges) and the array Edges[] (Where Edges[i] denoting an undirected edge between Edges[i][0] and Edges[i][1] with a flow capacity of Edges[i][2]), and returns the integer denoting the maximum flow from 1 to N.

Expected Time Complexity: O(max_flow*M)
Expected Auxiliary Space: O(N+M)
Where max_flow is the maximum flow from 1 to N
*/


class Solution
{
public:
   int bfs(int s, int d, vector<int> &parent, vector<vector<int>> &adj, int n)
    {
        vector<int> vis(n + 1);
        queue<int> q;
        q.push(s);
        vis[s] = 1;

        while(!q.empty()) {
            auto u = q.front();
            q.pop();

            for(int i = 1; i <= n; i++) {
                if(!vis[i] and adj[u][i] != 0) {
                    q.push(i);
                    parent[i] = u;
                    vis[i] = 1;
                }
            }
        }

        return vis[d];
    }
    int findMaxFlow(int n,int m,vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1, vector<int> (n + 1));
        for(auto i: edges) {
            adj[i[0]][i[1]] += i[2];
            adj[i[1]][i[0]] += i[2];
        }

        int pathFlow = 0;
        int src = 1, dest = n;
        vector<int> parent(n + 1, -1);
        while(bfs(src, dest, parent, adj, n)) {
            int minFlow = INT_MAX;
            int i = dest;
            while(parent[i] != -1) { // find all the min path from source to dest and find the min weight from that path and then add that path to all nodes on that path;
                minFlow = min(minFlow, adj[parent[i]][i]);
                i = parent[i];
            }

            i = dest;
            while(parent[i] != -1) {
                adj[parent[i]][i] -= minFlow; // residual capacity = initial cap - minFlow (formula);
                i = parent[i];
            }

            pathFlow += minFlow;
        }
        return pathFlow;

    }
};

