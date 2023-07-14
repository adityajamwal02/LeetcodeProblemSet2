/// Graph On an array : Codechef

#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent,rank,size;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
    return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u]=ulp_v;
        else if(rank[ulp_u]>rank[ulp_v]) parent[ulp_v]=ulp_u;
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

vector<int> prime{29, 31, 37, 41, 43, 47};

void solve(){
    map<int,int> mp;
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    DSU ds(n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(__gcd(arr[i],arr[j])==1){
                ds.unionBySize(i,j);
            }
        }
    }
    bool flag=false;
    int x=ds.findParent(1);
    for(int i=2;i<=n;i++){
        int ax1=ds.findParent(i);
        if(ax1!=x){
            flag=true;
            break;
        }
    }
    if(flag){
        for(auto it : prime){
            if(mp[it]==0){
                arr[1]=it;
                break;
            }
        }
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" \n"[i==n];
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
