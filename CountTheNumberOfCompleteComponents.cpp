/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
Return the number of complete connected components of the graph.
A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
A connected component is said to be complete if there exists an edge between every pair of its vertices.

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.

Example 2:
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
*/

class Solution {
public:
    void dfs(int node, vector<unordered_set<int>>& adjList, unordered_set<int>& visited) {
        visited.insert(node);
        for (int neighbor : adjList[node]) {
            if (visited.count(neighbor) == 0) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjList(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
        unordered_set<int> visited;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (visited.count(i) == 0) {
                dfs(i, adjList, visited);
                count++;
            }
        }

        return count;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjList(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
        unordered_set<int> visited;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited.count(i) == 0) {
                unordered_set<int> component;
                dfs(i, adjList, component);
                bool isComplete = true;
                for (int node : component) {
                    for (int neighbor : component) {
                        if (node != neighbor and !adjList[node].count(neighbor)) {
                            isComplete = false;
                            break;
                        }
                    }
                    if (!isComplete) {
                        break;
                    }
                }

                if (isComplete) {
                    count++;
                }
                visited.insert(component.begin(), component.end());
            }
        }
    return count;
    }
};
