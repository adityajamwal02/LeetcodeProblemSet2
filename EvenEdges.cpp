/// Even Edges : Codechef  : Problem Code: EVEDG

#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long int


#define Dd cout<<1;
#define EE endl
#define RR return
#define pb push_back


const int NN=1e5+1;
vector<int> adj[NN];
vector<int> ans(NN);
vector<int> sum(NN);
vector<int> c(NN);
int e,n;

void cal2()
{
    int even=1;

    for(int i=1;i<=n;i++)
    {
        if(even==1 && adj[i].size()!=0)
        {
            ans[i]=2;
            ans[adj[i][0]]=3;
            even=0;
        }
        if(ans[i]==1) if(adj[i].size()==0) ans[i]=2;
    }
    cout<<3<<EE;
    for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
            cout<<EE;
}

void cal1()
{
    int odd=0;

    for(int i=1;i<=n;i++)
        if(adj[i].size()%2) odd=1;

    if(odd==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()%2==1 && odd==1)
                ans[i]=2,odd=0;
            if(adj[i].size()==0) if(ans[i]==1) ans[i]=2;
        }
        cout<<2<<EE;
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
            cout<<EE;
        RR;
    }

    cal2();
}

void solve()
{

    cin>>n>>e;
    for(int i=0;i<=n;i++) adj[i].clear(),ans[i]=1;
    for(int i=0;i<e;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].pb(y); adj[y].pb(x);
    }


    if(e%2==0)
    {
        cout<<1<<EE;
        for(int i=1;i<=n;i++) cout<<1<<" "; cout<<EE;
    }
    else
    {
            cal1();

    }
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin>>t;

    for(int tt=1;tt<=t;tt++)
    {
        solve();
    }

    return 0;
}
