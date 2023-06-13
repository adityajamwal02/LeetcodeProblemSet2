/// Problem Code: PUSH7PA ; Codechef Problem

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> h(n);
	    map<int,int> mp;
	    for(int i=0;i<n;i++){
	        cin>>h[i];
	        mp[h[i]]++;
	    }
	    int sum=0;
	    for(auto it : mp){
	        sum=max(sum,it.first+it.second-1);
	    }
	    cout<<sum<<endl;
	}
	return 0;
}


