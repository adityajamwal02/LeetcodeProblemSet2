/// Root the Tree


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<bool> parent(n+1,true);
        int z=n;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            if(parent[v]){
                z--;
                parent[v]=false;
            }
        }
        cout<<z-1<<endl;
    }
    return 0;
}
