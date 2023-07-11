/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

Example 1:
Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:
The source vertex is 0. Hence, the shortest
distance of node 0 is 0 and the shortest
distance from node 1 is 9.

Example 2:
Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.
*/


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int wt=it[1];
                int adjNode=it[0];
                if(dis+wt<dist[adjNode]){
                    dist[adjNode]=dis+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
    return dist;
    }
};


/// Construct Adj list and then PQ Based Solution
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
	vector<pair<int,int>> adj[vertices];
	for(int i=0;i<edges;i++){
		int u=edge[i][0], v=edge[i][1], w=edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
	vector<int> dist(vertices,INT_MAX);
	dist[source]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0, source});
	while(!pq.empty()){
		int node=pq.top().second;
		int dis=pq.top().first;
		pq.pop();
		for(auto it : adj[node]){
			int stop=it.first;
			int weight=it.second;
			if(dis+weight < dist[stop]){
				dist[stop]=dis+weight;
				pq.push({dist[stop], stop});
			}
		}
	}
	return dist;
}


/// Set based solution


vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
	vector<pair<int,int>> adj[vertices];
	for(int i=0;i<edges;i++){
		int u=edge[i][0], v=edge[i][1], w=edge[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
	vector<int> dist(vertices,INT_MAX);
	dist[source]=0;
	set<pair<int,int>> st;
    st.insert({0, source});
	while(!st.empty()){
		auto it=*st.begin();
		int node=it.second;
		int dis=it.first;
		st.erase(it);
		for(auto it : adj[node]){
			int stop=it.first;
			int weight=it.second;
			if(dis+weight<dist[stop]){
				dist[stop]=dis+weight;
				st.insert({dist[stop],stop});
			}
		}
	}

    return dist;
}
