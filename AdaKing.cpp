/// Ada King : Codechef Question Problem Code: ADAKNG


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,c,k;
	    cin>>r>>c>>k;
	    int result=0;
	    for(int i=1;i<=8;i++){
	        for(int j=1;j<=8;j++){
	            if(max(abs(i-r),abs(j-c))<=k) result++;
	        }
	    }
	    cout<<result<<endl;
	}
	return 0;
}
