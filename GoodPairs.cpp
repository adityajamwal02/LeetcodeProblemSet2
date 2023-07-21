/// Good Pairs : codechef: Problem Code: GOODPAIRS

// Brute

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int counter=0;
	    vector<int> a(n), b(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(a[i]==b[j] and a[j]==b[i]) counter++;
	        }
	    }
	   cout<<counter<<endl;
	}
	return 0;
}

// Accepted

#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int counter=0;
	    map<pair<int,int>,int> mp;
	    vector<int> a(n), b(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    for(int i=0;i<n;i++){
	        counter+=mp[{b[i],a[i]}];
	        mp[{a[i],b[i]}]++;
	    }
	   cout<<counter<<endl;
	}
	return 0;
}
