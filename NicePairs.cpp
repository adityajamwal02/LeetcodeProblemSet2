/// Nice Pairs : Codechef

/// (Brute) TLE

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int count=0;
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if((j-i)==abs(s[j]-s[i])) count++;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}

/// Better Brute (limiting range of j) -> O(n) TC

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int count=0;
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n and j<=i+9;j++){
	            if((j-i)==abs(s[j]-s[i])) count++;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
