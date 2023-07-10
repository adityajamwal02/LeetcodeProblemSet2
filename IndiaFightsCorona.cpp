/// India Fights Corona : Codechef : Problem Code: CORONA


// Always consider the edge cases when thinking of solutions.
// Edge cases for the given variables for all their combinations.


#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ordered set

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// *a.find_by_order(k); -->  find kth element
// a.order_of_key(x);  -->  find no. of elements smaller than x
// *a.lower_bound(x);   -->  first element >= x
// *a.upper_bound(x);   -->  first element > x

//less --> less_equal to make it multiset
//less --> greater to store in descending order
//less --> comp to make comparator of your choice
//..<int, null_type.. change int to your data type of choice like ll , double etc.

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define all(v) v.begin()+1,v.end()
#define nline cout<<"\n"
#define prep(a) a.clear(); a.resize(n+1);
#define debug(x) cout<<#x<<" = "; _print(x); cout<<"\n";
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int N=200005;
const ll INF=1e18;
const ll mod=1e9 + 7;

vi pfs(10000000,-1);
vll factorial(10000005,1);

//vvi G(N,vi(0));
//vvi T(N,vi(0));



template<class T> void _print(T x);
template<class T,class V> void _print(pair<T,V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> s);
template<class T> void _print(multiset<T> s);
template<class T> void _print(unordered_set<T> s);
template<class T,class V> void _print(map<T,V> mp);
template<class T,class V> void _print(multimap<T,V> mp);
template<class T,class V> void _print(unordered_map<T,V> mp);

template<class T> void _print(T x){ cout<<x; }
template<class T,class V> void _print(pair<T,V> p){ cout<<"{"; _print(p.ff); cout<<","; _print(p.ss); cout<<"}"; }
template<class T> void _print(vector<T> v){ cout<<"[ "; for(auto it=v.begin()+1; it!=v.end(); it++){ _print(*it); cout<<((it+1==v.end())?"":","); } cout<<" ]"; }
template<class T> void _print(set<T> s){ cout<<"( "; for(auto it=s.begin(); it!=s.end(); it++){ _print(*it); cout<<((it==--s.end())?"":","); } cout<<" )"; }
template<class T> void _print(multiset<T> s){ cout<<"( "; for(auto it=s.begin(); it!=s.end(); it++){ _print(*it); cout<<((it==--s.end())?"":","); } cout<<" )"; }
template<class T> void _print(unordered_set<T> s){ cout<<"( "; for(auto it=s.begin(); it!=s.end(); it++){ _print(*it); cout<<((it==--s.end())?"":","); } cout<<" )"; }
template<class T,class V> void _print(map<T,V> mp){ cout<<"[ "; for(auto it=mp.begin(); it!=mp.end(); it++){ _print(*it); cout<<((it==--mp.end())?"":" , "); } cout<<" ]"; }
template<class T,class V> void _print(multimap<T,V> mp){ cout<<"[ "; for(auto it=mp.begin(); it!=mp.end(); it++){ _print(*it); cout<<((it==--mp.end())?"":" , "); } cout<<" ]"; }
template<class T,class V> void _print(unordered_map<T,V> mp){ cout<<"[ "; for(auto it=mp.begin(); it!=mp.end(); it++){ _print(*it); cout<<((it==--mp.end())?"":" , "); } cout<<" ]"; }





bool isPrime(int n){int lim=sqrt(n); loop(i,2,lim){ if(n%i==0) return false;} return true;} // returns whether n is prime or not - O(sqrt(n))
ll gcd(ll a,ll b){ if(a==0) return b; return gcd(b%a,a); } // calculates gcd  - O(log(min(a,b)))
ll binpow(ll a,ll b,ll m){ ll res=1; while(b>0){ if(b&1) res=(res*a)%m; a=(a*a)%m; b>>=1; }return res; } // calculates (a^b)%m  - O(log2(b))
vpii peter(int n){ vpii res; int cnt=0,lim=sqrt(n); loop(i,2,lim){ while(n%i==0){ cnt++; n/=i; } if(cnt>0) res.pb({i,cnt}); cnt=0; } if(n>2) res.pb({n,1}); return res;}
// returns prime factors of n along with their corresponding power - O(sqrt(n))
vi sieve1(ll n){ vi primes(n+1,1),primelist{2}; primes[0]=primes[1]=0;for(ll i=2;i<=n;i+=1) if(primes[i]){ primelist.pb(i); for(ll j=i*i;j<=n;j+=i)primes[j]=0;}return primelist;}
// returns list of primes upto n - almost O(n) ( O(nloglogn) )
vi sieve2(ll n){ vi primes(n+1,1); primes[0]=primes[1]=0;for(ll i=2;i<=n;i+=1) if(primes[i]){for(ll j=i*i;j<=n;j+=i)primes[j]=0;}return primes;}
// returns binary array with elements at prime number position set(1) and composite unset(0), i.e. ,if p is prime arr[p]=1  - almost O(n) ( O(nloglogn) )
vvi factor_sieve(int n){ vvi factors(n+1,vi(0)); loop(i,1,n){ int j=i; while(j<=n){ factors[j].pb(i);j+=i; }} return factors; }
// finds all factors of all numbers from 1 to n  - O(nlogn)
void pf_sieve(){for(ll i=2;i<=10000000;i++)if(pfs[i]==-1)for(ll j=i;j<=10000000;j+=i)if(pfs[j]==-1) pfs[j]=i;}
// calculates lowest smallest prime factor of every number upto 10^7 in almost O(n)
vi pif_zation(int n){vi ans;while(n>1){ans.pb(pfs[n]);int tv1=pfs[n];while(n%tv1==0) n/=tv1;}return ans;}
// returns vector of prime factors of n with the help of pf_sieve() in O(log n)



void comp_fact(){loop(i,2,10000005) factorial[i]=(factorial[i-1]*i)%mod;}
ll mmi(ll n,ll m){return binpow(n,m-2,m);}
ll multiply(ll x,ll y, ll m){return ((1LL*x*y)%m);}
ll divide(ll x,ll y,ll m){return multiply(x,mmi(y,m),m);}
ll nCr(ll n,ll r, ll m){return divide(factorial[n],multiply(factorial[n-r],factorial[r],m),m);}
ll nPr(ll n,ll r,ll m){return divide(factorial[n],factorial[n-r],m);}


vector<vector<pair<ll,ll>>> G;

void dijkstra(ll source,ll n)
{
    vll vis(N,0);
    vll dis(N,INF);

    multiset<pair<ll,ll>> st;

    st.insert({0,source});

    dis[source] = 0;

    while(st.size()>0)
    {
        auto node = *st.begin();
        ll v = node.ss;
        ll dist = node.ff;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child: G[v])
        {
            ll child_v = child.ff;
            ll wt = child.ss;
            if(dis[v] + wt < dis[child_v])
            {
                dis[child_v] = dis[v] + wt;
                st.insert({dis[child_v],child_v});
            }
        }
    }

    loop(i,1,n) cout<<dis[i]<<" \n"[i==n];
}




void mrinmoy(){

    ll n,m,k; cin>>n>>m>>k; vector<pair<ll,ll> > src(k+1); prep(G);

    loop(i,1,k) cin>>src[i].ff>>src[i].ss;

    loop(i,1,m)
    {
        ll a,b,d; cin>>a>>b>>d;
        G[a].pb({b,d}); G[b].pb({a,d});
    }

    loop(i,1,k)
    {
        G[0].pb({src[i].ff,src[i].ss});
        G[src[i].ff].pb({0,src[i].ss});
    }

    dijkstra(0,n);



}

int main() {
	// your code goes here

  /*#ifendef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif*/

    fastio;
    int tc;
    cin>>tc;
    while(tc--){
	    mrinmoy();
    }
	return 0;
}

// Basic DFS (Depth First Search) and BFS (Breadth First Search) algorithm

/*void dfs(int v,int par=0)
{
    for(auto &child : G[v])
    {
        if(child==par) continue;
        dfs(child,v);
    }
}

void bfs(int s)
{
    vi vis(N,0);
    queue<int> q; q.push(s); vis[s]=1;
    while(!q.empty())
    {
        int curr_v=q.front();
        q.pop();
        for(int child:G[curr_v])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
            }
        }
    }
}

// BFS in matrix

void bfs(int i,int j)
{
    queue<pii> q; q.push({i,j}); vis[1][1]=1;
    while(!q.empty())
    {
        auto pt = q.front(); q.pop();
        for(auto &i: mov)
        {
            int x1 = pt.first + i.first, y1 = pt.second + i.second;
            if(isValid(x1,y1,n,m))
            {
                if(vis[x1][y1]){ continue; }
                else{ vis[x1][y1]=1; q.push({x1,y1}); }
            }
        }
    }
}*/
