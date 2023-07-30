/// Tourists in Mancunia : Codechef

#include <bits/stdc++.h>
using namespace std;

const int N=100005;
set<int>adj[N];
vector<int>vis;
map<pair<int,int>,int >road;

void dfs(int k){
    vis.push_back(k);
     while(!adj[k].empty()){
            int ii = *adj[k].begin();
            adj[k].erase(ii);
            adj[ii].erase(k);
            road[{ii,k}]++;
            dfs(ii);

    }
}

int main() {
	int n,e;
	cin>>n>>e;
	vector<int>deg(n+1,0);
	vector<pair<int,int>> edge;
	for(int i=0;i<e;i++){
	    int a,b;cin>>a>>b;
	    adj[a].insert(b);
	    adj[b].insert(a);
	    edge.push_back({a,b});
	    deg[a]++;deg[b]++;
	}
	for(int i=1;i<=n;i++){
	    if(deg[i]&1){
	        cout<<"NO"<<endl;return 0;
	    }
	}
	dfs(1);
	if(vis.size()<n){
	    cout<<"NO"<<endl;return 0;
	}
	cout<<"YES"<<endl;
	for(auto x:edge){
	    if(road.find(x)==road.end())  cout<<x.first<<" "<<x.second<<endl;
	    else
	        cout<<x.second<<" "<<x.first<<endl;
	}
	return 0;
}
