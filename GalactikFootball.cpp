/// Problem Code: GALACTIK

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N=1e5;
vector<vector<int> > v(N+1);
vector<bool> vis(N+1);
vector<int> values(N+1);

void dfs(int i,int &t,int par=-1){
    vis[i]=true;
    if(values[i]>=0) t=min(t,values[i]);
    for(ll j=0;j<v[i].size();j++){
        if(vis[v[i][j]]==false)
        {
          dfs(v[i][j],t,i);

        }
    }
}

void solve()
{

    ll n,k;
    cin>>n>>k;
    vis.resize(n+1);
    values.resize(n+1);
    v.resize(n+1);
    for(ll i=1;i<=n;i++) vis[i]=0;
    for(ll i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(ll i=1;i<=n;i++){
        cin>>values[i];
    }
    vector<ll> ans;
    int sum=0, minn=INT_MAX, l=0;
    bool flag=true;
    for(ll i=1;i<=n;i++){
       if(vis[i]==false){
           int c=INT_MAX;
           dfs(i,c);
           if(c==INT_MAX)
           {
               flag=false;
           }
          l++;
          sum+=c;
          minn=min(c,minn);
       }
    }
    if(flag==false and l>1)
    {
       cout<<-1<<endl;
       return ;
    }else if(l==1)
    {
       cout<<0<<endl;
       return ;
    }
    else
    {
       cout<<sum+((l-2)*minn)<<endl;
    }
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=1;
    // cin>>n;
    while(n--)
    {
        solve();

    }
    return 0;
}
