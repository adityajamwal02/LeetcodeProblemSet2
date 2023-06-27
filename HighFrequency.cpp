/// Codechef : Problem Code: HIGHFREQ


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        mp[x]++;
	    }
	    priority_queue<int> pq;
	    for(auto it : mp){
	        pq.push(it.second);
	    }
	    if(pq.size()==1){
	        cout<<ceil(pq.top()/2.0)<<endl;
	    }else{
	        int largest=pq.top();
    	    pq.pop();
    	    int secLargest=pq.top();
    	    pq.pop();
    	    cout<<max((int)ceil(largest/2.0),secLargest)<<endl;
	    }
	}
	return 0;
}
