/// Increasing Decreasing


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int maxFreq=0, flag=1;
	    vector<int> arr(n);
	    vector<int> v1,v2;
	    map<int,int> mp;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        mp[arr[i]]++;
	        maxFreq=max(maxFreq,arr[i]);
	    }
	    if(mp[maxFreq]>1 or (mp.size()<(n/2)+1)){
	        flag=0;
	    }else{
	        for(auto it : mp){
	            if(it.second>=3){
	                flag=0;
	                break;
	            }else if(it.second>1){
	                v1.push_back(it.first);
	                v2.push_back(it.first);
	            }else{
	                v1.push_back(it.first);
	            }
	        }
	        sort(v1.begin(),v1.end());
	        sort(v2.rbegin(),v2.rend());
	        for(int i=0;i<v2.size();i++){
	            v1.push_back(v2[i]);
	        }
	    }
	    if(flag==0) cout<<"NO"<<endl;
	    else{
	        cout<<"YES"<<endl;
	        for(auto it : v1){
	            cout<<it<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
