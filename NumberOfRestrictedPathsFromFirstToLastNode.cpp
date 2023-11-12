/*
There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.

Example 1:
Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
Output: 3
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5

Example 2:
Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
Output: 1
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
*/

class Solution {
public:
    int mod=1e9+7;
    long long solve(int node, vector<int> &dist, vector<pair<int,int>> adj[], vector<long long> &dp){
        if(node==1) return 1;
        if(dp[node]!=-1) return dp[node];
        int currVal=dist[node];
        long long result=0;
        dp[node]=1;
        for(auto it : adj[node]){
            int nextIndex=it.first, nextDist=dist[nextIndex];
            if(nextDist>currVal){
                result=(result+solve(nextIndex,dist,adj,dp))%mod;
            }
        }
    return dp[node]=result;
    }

    int helper(int n, vector<pair<int,int>> adj[]){
        vector<int> dist(n+1,INT_MAX);
        dist[n]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,n});
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int currIndex=it.first, currDis=it.second;
                if(dist[currIndex]>distance+currDis){
                    dist[currIndex]=distance+currDis;
                    pq.push({dist[currIndex],currIndex});
                }
            }
        }
        vector<long long> dp(n+1,-1);

    return solve(n,dist,adj,dp);
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[n+1];
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
    return helper(n,adj);
    }
};
