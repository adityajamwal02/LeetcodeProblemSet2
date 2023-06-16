/// Turn It: Codechef

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int u,v,a,s;
        cin>>u>>v>>a>>s;
        if(u==v and v==1) cout<<"YES"<<endl;
        else{
            float speed=sqrt((u*u - (2*a*s)));
            if(speed>v) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }

    return 0;
}
