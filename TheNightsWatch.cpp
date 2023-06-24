/// Nights Watch : Problem Code: WTCH // Codechef

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string str;
	    cin>>str;
	    // N Watchtowers -> 1 person , nighter's watch
	    // Idea : Binary String with without consecutive 1's
	    int counter=0;
	    for(int i=0;i<n;i++){
	        if(str[i]=='0' and (i==0 or str[i-1]=='0') and (i==n-1 or str[i+1]=='0')){
	            str[i]='1';
	            counter++;
	        }
	    }
	    cout<<counter<<endl;
	}
	return 0;
}

