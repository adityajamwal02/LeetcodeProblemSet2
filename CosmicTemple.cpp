/// Cosmic Temple : Codechef

/// Solution : Dijkstra Idea + Sum over all distances

#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> dijkstra(int src, int n, vector<pair<int,int>> adj[]){
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int node=pq.top().second;
		int dis=pq.top().first;
		pq.pop();
		for(auto it : adj[node]){
		    int stop=it.first;
		    int weight=it.second;
		    if(dis+weight<dist[stop]){
		        dist[stop]=dis+weight;
		        pq.push({dist[stop],stop});
		    }
		}
    }
    return dist;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	vector<pair<int,int>> adj[n];
	for(int i=0;i<n;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back({v,1});
	    adj[v].push_back({u,1});
	}
	vector<int> result(n);
	for(int i=0;i<n;i++){
	    int totalDistance=0;
	    vector<int> temp=dijkstra(i, n, adj);
	    for(int j=0;j<temp.size();j++){
	        totalDistance+=temp[j];
	    }
	result[i]=totalDistance;
	temp.clear();
	}
	for(int i=0;i<result.size();i++){
	    cout<<result[i]<<" ";
	}
	cout<<endl;

	return 0;
}
