/// Shortest Path In DAG : Generalize code for dijkstra algo, with unit weight / different unique weights, Using PQ implementation


vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int,int>> adj[n];
    vector<int> dist(n,INT_MAX);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0], v=edges[i][1], w=edges[i][2];
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[0]=0;
    pq.push({0, 0});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int adjNode=it.first;
            int weight=it.second;
            if(dis+weight<dist[adjNode]){
                dist[adjNode]=dis+weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    for(int i=0;i<dist.size();i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }
return dist;
}
