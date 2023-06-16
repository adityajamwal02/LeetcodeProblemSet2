/// Guessing Game

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long n,m;
	    cin>>n>>m;
	    if((n%2!=0) and (m%2!=0)) cout<<((m*n-1)/2)<<"/"<<(m*n)<<endl;
	    else cout<<"1/2"<<endl;
	}
	return 0;
}
