/// List of lists : codechef : Problem Code: LISTLIST


#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int> mp;
        int x, maxi=0;
        for(int i=0;i<n;i++){
            cin>>x;
            mp[x]++;
            maxi=max(maxi,mp[x]);
        }
        if(mp.size()==1) cout<<0<<endl;
        else if(maxi<2) cout<<-1<<endl;
        else{
            n=n-maxi;
            cout<<n+1<<endl;
        }
    }
	return 0;
}
