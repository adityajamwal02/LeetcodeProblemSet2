/// Even Splits : Codechef Problem Code: EVENSPLIT

/// Observation is important

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    if(n>2){
	        sort(s.begin(),s.end());
	    }
	    cout<<s<<endl;
	}
	return 0;
}
