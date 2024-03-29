/// Codechef :Problem Code: TINOI17A : Fence-INOI 2017


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define endl "\n"

const int N = 1e6+10;
const ll INF = 1e18+10;
const int mod = 20011;

pii a[N];
set<pii> s, visited;
queue<pii> q;

int bfs(int src)
{
    int ans=0;

    q.push(a[src]);

    while(!q.empty())
    {
        pii v = q.front();
        q.pop();
        if(visited.count(v)) continue;
        visited.insert(v);
        ans += 4;
        if(s.count({v.first-1, v.second})){
            ans--;
            if(!visited.count({v.first-1, v.second}))
                q.push({v.first-1, v.second});
        }
        if(s.count({v.first+1, v.second})){
            ans--;
            if(!visited.count({v.first+1, v.second}))
                q.push({v.first+1, v.second});
        }

        if(s.count({v.first, v.second-1})){
            ans--;
            if(!visited.count({v.first, v.second-1}))
                q.push({v.first, v.second-1});
        }

        if(s.count({v.first, v.second+1})){
            ans--;
            if(!visited.count({v.first, v.second+1}))
                q.push({v.first, v.second+1});
        }

    }

    return ans;
}


void solve()
{
    int r, c, n;
    cin >> r >> c >> n;

    for(int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;

    for(int i=0; i<n; i++)
        s.insert({a[i].first, a[i].second});

    int ans=0;

    for(int i=0; i<n; i++){
        if(!visited.count({a[i].first, a[i].second})){
            ans = max(ans, bfs(i));
        }
    }

    cout << ans << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
	return 0;
}
