/// find tree diameter : Problem Code:DIAMTREE

#include <bits/stdc++.h>
using namespace std;

int result=0;

int diameter(int curr, int prev, vector<vector<int>> &edges){
    int lh=0, rh=0, counter=0;
    bool root=true;
    for(auto edge : edges[curr]){
        if(edge!=prev){
            counter++;
            root=false;
            int ans=1+diameter(edge,curr,edges);
            if(ans>lh){
                rh=lh;
                lh=ans;
            }else{
                if(ans>rh) rh=ans;
            }
        }
    }
    if(root==false){
        result=max({result,lh,rh});
        result=max({result,lh+rh});
    return max(lh,rh);
    }
    return 0;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> edges(n+1,vector<int>());
	    for(int i=1;i<n;i++){
	        int u,v;
	        cin>>u>>v;
	        edges[u].push_back(v);
	        edges[v].push_back(u);
	    }
	    diameter(1,0,edges);
	    cout<<result<<endl;
	    result=0;
	}
	return 0;
}
