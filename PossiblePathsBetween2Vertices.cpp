/*
Given a Directed Graph having V nodes numbered from 0 to V-1, and E directed edges. Given two nodes, source and destination, count the number of ways or paths between these two vertices in the directed graph. These paths should not contain any cycle.
Note: Graph doesn't contain multiple edges, self-loop, and cycles.


Example 1:
Input:
V = 5, E = 7
Edges of Graph =
{0, 1}
{0, 2}
{0, 4}
{1, 3}
{1, 4}
{2, 4}
{3, 2}
source = 0
destination = 4

Output: 4
Explanation:

There are 4 paths from 0 to 4.
0 -> 4
0 -> 1 -> 4
0 -> 2 -> 4
0 -> 1 -> 3 -> 2 -> 4

Example 2:
Input:
V = 4, E = 5
Edges of Graph =
{0, 1}
{0, 3}
{1, 2}
{1, 3}
{2, 3}
source = 0
destination = 3
Output: 3
Explanation:

There are 3 paths from 0 to 3.
0 -> 3
0 -> 1 -> 3
0 -> 1 -> 2 -> 3

Your task:
You don't need to read, input, or print anything. Your task is to complete the function countPaths(), which takes the integer V denoting the number of vertices, adjacency list adj, integer source, and destination as input parameters and returns the number of paths in the graph from the source vertex to the destination vertex.


Expected Time Complexity: O(V!)
Expected Auxiliary Space: O(V)
*/


class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.

    void dfs(int source, int destination, vector<int> adj[], vector<bool>& visited, int& count) {
        if (source == destination) {
            count++;
            return;
        }

        visited[source] = true;

        for (int neighbor : adj[source]) {
            if (!visited[neighbor]) {
                dfs(neighbor, destination, adj, visited, count);
            }
        }

        visited[source] = false;
    }

    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<bool> visited(V, false);
        int count = 0;
        dfs(source, destination, adj, visited, count);
        return count;
    }
};
