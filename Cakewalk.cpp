/// Cakewalk : Codechef : Problem Code: CKWLK


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int x=0, y=0;
	    while(n%10==0){
	        n/=10;
	        x++;
	    }
	    while(n%2==0){
	        n/=2;
	        y++;
	    }
	    if(n!=1 or y>x) cout<<"No"<<endl;
	    else cout<<"Yes"<<endl;
	}
	return 0;
}
