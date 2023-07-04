/// SubTree Removal : Codechef : Problem Code: SUBREM

#include <bits/stdc++.h>
using namespace std;

long long dfs(int prev, int node, long long &x, vector<long long> &val, vector<int> adj[]){
    long long sum=0;
    for(auto it : adj[node]){
        if(it!=prev){
            sum+=dfs(node,it,x,val,adj);
        }
    }
    sum+=val[node];
return max(sum,-x);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long n, x;
	    cin>>n>>x;
	    vector<long long> val(n);
	    for(int i=0;i<n;i++){
	        cin>>val[i];
	    }
	    vector<int> adj[n];
	    for(int i=0;i<n-1;i++){
	        int u,v;
	        cin>>u>>v;
	        adj[u-1].push_back(v-1);
	        adj[v-1].push_back(u-1);
	    }
	    long long result=dfs(-1,0,x,val,adj);
	cout<<result<<endl;
	}
	return 0;
}

