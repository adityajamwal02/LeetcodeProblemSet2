/// Dijkstra Algorithm

#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> dijkstra(vector<pair<int,int>> adj[], int n, int edges, int source){
	vector<int> dist(n,INT_MAX);
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

int main(){
    //n=vertices
    cin>>n;

    int graph[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    vector<pair<int,int>> adj[n];
    int edges=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j and graph[i][j]!=0){
                edges++;
                adj[i].push_back({j,graph[i][j]});
                adj[j].push_back({i,graph[i][j]});
            }
        }
    }
    edges/=2;
    vector<int> result=dijkstra(adj,n,edges,0);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
