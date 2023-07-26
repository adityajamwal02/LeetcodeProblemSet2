/// Abdullah and Toll Discounts : Problem Code: ABDTOLL : Codechef


#include <bits/stdc++.h>
using namespace std;
#define int long long int

int dfs(vector<int> adj[], int source, int prev, vector<int> &nums, int k, int &coupon){
    int ans=0;
    for(auto it : adj[source]){
        if(it!=prev){
            int temp=dfs(adj,it,source,nums,k,coupon);
            ans=max(ans,temp);
        }
    }
    ans+=nums[source];
    if(ans>k){
        coupon+=(ans-k);
        ans=k;
    }
return ans;
}

int32_t main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x,k;
	    cin>>n>>x>>k;
	    vector<int> nums(n);
	    for(int i=0;i<n;i++){
	        cin>>nums[i];
	    }
	    vector<int> adj[n];
	    for(int i=1;i<n;i++){
	        int u, v;
	        cin>>u>>v;
	        adj[u-1].push_back(v-1);
	        adj[v-1].push_back(u-1);
	    }
	    int coupon=0;
	    dfs(adj,x-1,-1,nums,k,coupon);
	    cout<<2*coupon<<endl;
	}
	return 0;
}

