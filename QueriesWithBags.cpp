/// Queries With Bags : Codechef :Problem Code: DSUBAGS

#include<bits/stdc++.h>
using namespace std;

int dist=0;

class DSU{
public:

    vector<int> parent,size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findParent(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
    return parent[node]=findParent(parent[node]);
    }

    void Union(int a, int b)
    {
        int x=findParent(a);
        int y=findParent(b);
        if(x==y)
        {
            return;
        }
        else{
            if(size[x]<size[y])
            {
                parent[x]=y;
                size[y]+=size[x];
                dist--;
            }
            else{
                parent[y]=x;
                size[x]+=size[y];
                dist--;
            }
        }
    }
};

int main() {
    int n,q;
	cin>>n>>q;
	dist=n;
	DSU ds(n);
	while(q--)
	{
	    int type;
	    cin>>type;
	    if(type==1)
	    {
	        int a,b;
	        cin>>a>>b;
	        ds.Union(a,b);
	    }
	    else if(type==2){
	        int a,b;
	        cin>>a>>b;
	        if(ds.findParent(a)==ds.findParent(b))
	        {
	            cout<<"YES"<<endl;
	        }
	        else{
	            cout<<"NO"<<endl;
	        }
	    }
	    else{
	        cout<<dist<<endl;
	    }
	}
	return 0;
}
