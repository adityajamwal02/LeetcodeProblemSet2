/*
Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.
Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible.
Students must be placed in seats in good condition.

Example 1:
Input: seats = [["#",".","#","#",".","#"],
                [".","#","#","#","#","."],
                ["#",".","#","#",".","#"]]
Output: 4
Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam.

Example 2:
Input: seats = [[".","#"],
                ["#","#"],
                ["#","."],
                ["#","#"],
                [".","#"]]
Output: 3
Explanation: Place all students in available seats.

Example 3:
Input: seats = [["#",".",".",".","#"],
                [".","#",".","#","."],
                [".",".","#",".","."],
                [".","#",".","#","."],
                ["#",".",".",".","#"]]
Output: 10
Explanation: Place students in available seats in column 1, 3 and 5.
*/


vector<int> bfs(const vector<vector<int>>& graph, int source, int target) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == target) {
            return parent;
        }

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (!visited[neighbor] && graph[node][neighbor] >= 1) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    return parent;
}

struct GraphData {
    int seatCount;
    vector<vector<int>> graph;
    int source;
    int target;
};

GraphData buildGraph(const vector<vector<char>>& seats) {
    int m = seats.size();
    int n = seats[0].size();

    int source = m * n;
    int target = m * n + 1;

    vector<vector<int>> graph(m * n + 2, vector<int>(m * n + 2, 0));
    int seatCount = 0;

    vector<vector<int>> directions = {{0, -1}, {-1, -1}, {1, -1}, {0, 1}, {-1, 1}, {1, 1}};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (seats[i][j] == '#') {
                continue;
            }

            seatCount++;
            int node = i * n + j;

            if (j % 2 == 0) {
                graph[source][node] = 1;

                for (const auto& dir : directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if (x < 0 || x >= m || y < 0 || y >= n || seats[x][y] == '#') {
                        continue;
                    }

                    int neighbor = x * n + y;
                    graph[node][neighbor] = 1;
                }
            } else {
                graph[node][target] = 1;
            }
        }
    }

    return GraphData{seatCount, graph, source, target};
}

int getMaxNetworkFlow(vector<vector<int>>& graph, int source, int target) {
    int flow = 0;
    while (true) {
        vector<int> parent = bfs(graph, source, target);

        if (parent[target] == -1) {
            break;
        }

        int v = target;

        while (v != source) {
            int u = parent[v];
            graph[u][v]--;
            graph[v][u]++;
            v = u;
        }

        flow++;
    }
    return flow;
}

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        GraphData graphData = buildGraph(seats);
        int maxCheatingAsPerFlowNetwork = getMaxNetworkFlow(graphData.graph, graphData.source, graphData.target);

    return graphData.seatCount - maxCheatingAsPerFlowNetwork;
    }
};
