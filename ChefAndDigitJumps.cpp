/// Chef And Digit Jumps : Problem Code: DIGJUMP : Codechef

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    queue<int> q;
    vector<int> dist(n+1,0);
    vector<int> vis(n+1,0);
    vector<int> adj[11];
    for(int i=0;i<n;i++)
    {
        int val = (int) s[i]-'0';
        adj[val].push_back(i);
    }

    int start = 0;
    vis[0]=1;
    q.push(start);
    while(!q.empty())
    {
        int ind = q.front();
        q.pop();
        if(ind==n-1) break;
        int val = s[ind]-'0';
        for(int i=0;i<adj[val].size();i++)
        {
            if(vis[adj[val][i]]) continue;
            vis[adj[val][i]]=1;
            dist[adj[val][i]] = dist[ind]+1;
            q.push(adj[val][i]);
        }
        adj[val].clear();
        if(ind-1>=0 && ind-1<n && vis[ind-1]==0)
        {
            vis[ind-1]=1;
            q.push(ind-1);
            dist[ind-1]=dist[ind]+1;
        }
        if(ind+1>=0 && ind+1<n && vis[ind+1]==0)
        {
            vis[ind+1]=1;
            q.push(ind+1);
            dist[ind+1]=dist[ind]+1;
        }
    }
    cout<<dist[n-1]<<endl;
}

int main() {
	solve();
	return 0;
}
