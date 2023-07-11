/// Sticks and Rectangles: Codechef: Problem Code:RECSTI

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        mp[arr[i]]++;
	    }
	    if(n==1){
	        cout<<3<<endl;
	    }else{
    	    int counter=0, countPairs=0;
    	    for(auto it : mp){
    	        if(it.second%2==1){
    	            counter++;
    	        }
    	    }
    	    counter+=(n+counter)%4;
    	    cout<<counter<<endl;
	    }
	}
	return 0;
}
