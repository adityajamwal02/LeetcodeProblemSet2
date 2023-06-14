/// Codechef question : Problem Code: MAKEDIV3

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n]={0};
	    arr[0]=3;
	    arr[n-1]=3;
	    for(int i=0;i<n;i++){
	        cout<<arr[i];
	    }
	    cout<<endl;
	}
	return 0;
}
