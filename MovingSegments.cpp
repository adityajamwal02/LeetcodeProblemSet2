/// Moving Segments

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    map<int,vector<pair<int,int>>> mp;
	    for(int i=0;i<n;i++){
	        int a, b, speed;
	        cin>>a>>b>>speed;
	        if(mp.count(speed)>0){
	            mp[speed].push_back({a,b});
	        }else{
	            mp[speed]=vector<pair<int,int>>();
	            mp[speed].push_back({a,b});
	        }
	    }
	    bool isFound=false;
	    for(auto it : mp){
	        vector<pair<int,int>> list=it.second;
	        if(!isFound){
	            map<int,int> temp;
	            for(auto p : list){
	                temp[p.first]++;
	                temp[p.second + 1]--;
	            }
	            int intersections = 0;
	            for(auto p : temp){
	                intersections += p.second;
	                if(intersections>2){
	                    isFound = true;
	                    break;
	                }
	            }
	        }
	    }
	    if(!isFound) cout << "YES" << endl;
	    else cout << "NO" <<endl;
	}
	return 0;
}

