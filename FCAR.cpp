/// FCAR

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, r;
    cin >> n >> r;
    vector<int> heights(n + 1), costs(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> costs[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dist(n + 1, vector<int>(2, 1000000000000000));
    dist[1][0] = costs[1], dist[1][1] = costs[1];

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({dist[1][0], 1, 0});
    pq.push({dist[1][1], 1, 1});

    while (!pq.empty()) {
        vector<int> k = pq.top();
        int d = k[0];
        int node = k[1];
        int mode = k[2];
        pq.pop();

        for (auto x : adj[node]) {
            int money = dist[node][mode];
            if (heights[x] >= heights[node]) {
                if (mode != 0)
                    money += costs[node];

                if (money < dist[x][0]) {
                    dist[x][0] = money;
                    pq.push({dist[x][0], x, 0});
                }
            }

            money = dist[node][mode];
            if (heights[node] >= heights[x]) {
                if (mode != 1)
                    money += costs[node];

                if (money < dist[x][1]) {
                    dist[x][1] = money;
                    pq.push({dist[x][1], x, 1});
                }
            }
        }
    }

    int dis = min(dist[n][0], dist[n][1]);

    if (dis >= 1000000000000000)
        cout << -1;
    else
        cout << dis;

    return 0;
}
