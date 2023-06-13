/// Problem Code: REVERSE :: Codechef Question

#include<bits/stdc++.h>
using namespace std;

const int inf = 2000000000;
const static int N = 1e5+10;
vector<pair<int,int>> g[N];
vector<int> level(N, inf);
int bfs(int n)
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;

    while(!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();
        for(auto child:g[cur_v])
        {
            int c_v = child.first;
            int wt = child.second;
            if(level[cur_v] + wt < level[c_v])
            {
                level[c_v] = level[cur_v] + wt;
                if(wt==1) q.push_back(c_v);
                else q.push_front(c_v);
            }
        }
    }
    return (level[n] == inf ? -1 : level[n]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
       if(x==y) continue;
            g[x].push_back({y, 0});
            g[y].push_back({x, 1});
        }
    cout<<bfs(n)<<endl;

    return 0;
}
