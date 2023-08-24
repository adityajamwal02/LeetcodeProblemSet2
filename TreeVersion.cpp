/// TreeVersion

#include <bits/stdc++.h>



using namespace std;


#define int long long
vector<int> zeroes(100001,0);
vector<int> ones(100001,0);

int countZeroes(vector<vector<int>> &adj,vector<int> &zeroes,int i,int parent,vector<int> &w)
{
    for(auto x:adj[i])
    {
        if(x!=parent)
        {
            zeroes[i] += countZeroes(adj,zeroes,x,i,w);
        }
    }
    if(w[i]==0)
        zeroes[i]++;
    return zeroes[i];
}

int countOnes(vector<vector<int>> &adj,vector<int> &ones,int i,int parent,vector<int> &w)
{
    for(auto x:adj[i])
    {
        if(x!=parent)
        {
            ones[i] += countOnes(adj,ones,x,i,w);
        }
    }
    if(w[i]==1)
        ones[i]++;
    return ones[i];
}

struct comp{
    bool operator()(pair<int,int> &a,pair<int,int> &b)
    {
        return((a.second*b.first)<(b.second*a.first));
    }
};

int countInversions(vector<vector<int>> &adj,int i,int parent,vector<int> &zeroes,vector<int> &ones,vector<int> &w,vector<int> &inversions)
{
    vector<pair<int,int>> count;
    int sumZero = 0;
    for(auto x:adj[i])
    {
        if(x!=parent)
        {
            inversions[i] += countInversions(adj,x,i,zeroes,ones,w,inversions);
            count.push_back({zeroes[x],ones[x]});
            sumZero+=zeroes[x];
        }
    }
    if(w[i]==1)
        inversions[i]+=sumZero;
    sort(count.begin(),count.end(),comp());
    for(auto x:count)
    {
            inversions[i] += x.second*(sumZero-x.first);
            sumZero-=x.first;
    }
    return inversions[i];
}


signed main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> w(n+1);
	    for(int i=1;i<=n;i++)
	    {
	        cin>>w[i];
	    }
	    vector<vector<int>> adj(n+1);
	    for(int i=0;i<n-1;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        adj[x].push_back(y);
	        adj[y].push_back(x);
	    }
	    ones.assign(n+1,0);
	    zeroes.assign(n+1,0);
	    countZeroes(adj,zeroes,1,-1,w);
	    countOnes(adj,ones,1,-1,w);
	    vector<int> inversions(n+1,0);
	    int ans = countInversions(adj,1,-1,zeroes,ones,w,inversions);
	    cout<<ans<<endl;
	}
	return 0;
}
