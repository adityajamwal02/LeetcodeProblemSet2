/// Family Tree : Problem Code: FAMTREE // Codechef

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#define ll long long int
#define ld long double
#define inf 3e18 + 1
#define all(v) (v).begin(), (v).end()
#define N 5005
#define rep(l,r) for(ll i=l;i<r;i++)
#define F first
#define S second
using namespace std;
ll mod = 1e9 + 7;
ll expo(ll n, ll p) {
  // n%=m;
  ll res=1;
  while(p) {
    if(p&1) {
      res=res*n;
    }
    n=n*n;
    p>>=1;
  }
  return res;
}
int fun(int a, int b){
  if (b == 0)
    return a;
  return fun(b, a % b);
}

void dfs(vector<pair<int,int>>adj[],int v,int mx,int mn,int &ans) {
  for(auto i:adj[v]) {
    ans=max(ans,max(mx,i.second)-min(mn,i.second));
    dfs(adj,i.first,max(mx,i.second),min(mn,i.second),ans);
  }
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll test = 1;
  // cin>>test;
  while (test--){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) {
      cin>>a[i];
    }
    vector<pair<int,int>>adj[n];
    int root=-1;
    for(int i=0;i<n;i++) {
      int p;
      cin>>p;
      if(p==-1) {
        root=i;
      }
      else {
        adj[p-1].push_back({i,a[i]});
      }
    }
    int ans=0;
    dfs(adj,root,a[root],a[root],ans);
    cout<<ans<<endl;

  }

  return 0;
}
