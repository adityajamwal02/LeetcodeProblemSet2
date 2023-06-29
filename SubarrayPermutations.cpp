/// Subarray Permutations : Problem Code: SUBPERM


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    if(n==1) cout<<1<<endl;
	    else if(k==1) cout<<-1<<endl;
	    else{
	        cout<<1;
	        for(unsigned i = 2; i <= k - 1; i++)
    		    cout << ' ' << i;
	        for(unsigned i = n; i > k - 1; i--)
		        cout << ' ' << i;
	    cout<<endl;
	    }
	}
	return 0;
}

