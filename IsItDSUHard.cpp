/// Is it DSU Hard : Codechef : Problem Code: CFMAR04


/// Map Approach

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	unordered_map<string,int> mp;
	for(int i=0;i<n;i++){
	    string temp;
	    cin>>temp;
	    sort(temp.begin(),temp.end());
	    mp[temp]++;
	}
	int result=0;
	for(auto it : mp){
	    result=max(result,it.second);
	}
	cout<<result;
	return 0;
}
