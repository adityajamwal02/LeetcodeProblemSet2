/// Codechef Question : Rating -> 1700

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n), b(n-1);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n-1;i++){
	        cin>>b[i];
	    }
	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
	    map<int,int> mp;
	    for(int i=0;i<n-1;i++){
	        int m1=b[i]-a[i];
	        int m2=b[i]-a[i+1];
	        if(m1!=m2){
	            if(m1>0) mp[m1]++;
	            if(m2>0) mp[m2]++;
	        }else{
	            if(m1>0){
	                mp[m1]++;
	            }
	        }
	    }
	    for(auto it : mp){
	        if(it.second==n-1){
	            cout<<it.first<<endl;
	            break;
	        }
	    }
	}
	return 0;
}
