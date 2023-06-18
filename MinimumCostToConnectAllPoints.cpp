/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
*/

/// MST Approach (Prims / Kruskal)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int result=0, i=0, connected=0;
        vector<bool> vis(n);
        priority_queue<pair<int,int>> pq;
        while(++connected<n){
            vis[i]=true;
            for(int j=0;j<n;j++){
                if(!vis[j]){
                    int curr_x=points[i][0], next_x=points[j][0];
                    int curr_y=points[i][1], next_y=points[j][1];
                    pq.push({-(abs(curr_x-next_x)+abs(curr_y-next_y)) , j});
                }
            }
            while(vis[pq.top().second]) pq.pop();
            result-=pq.top().first;
            i=pq.top().second;
            pq.pop();
        }
    return result;
    }
};


/// Union Find Approach


class Solution {
public:
    int par[1001];
    int find(int a)
    {
        if(par[a] < 0)
            return a;
    return par[a] = find(par[a]);
    }

    void Union(int a, int b)
    {
        par[a] = b;
    }

    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) par[i] = -1;
        vector<pair<int, pair<int, int>>> adj;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int weight = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]);
                adj.push_back({weight, {i, j}});
            }
        }
        sort(adj.begin(), adj.end());
        int sum = 0;
        for(int i = 0; i < adj.size(); i++)
        {
            int a = find(adj[i].second.first);
            int b = find(adj[i].second.second);
            if(a != b)
            {
                sum += adj[i].first;
                Union(a, b);
            }
        }
    return sum;
    }
};
