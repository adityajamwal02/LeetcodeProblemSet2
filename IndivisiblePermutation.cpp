/// Indivisible Permutation : Codechef: Problem Code: INDIPERM


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> result;
	    result.push_back(n);
	    for(int i=1;i<n;i++){
	        result.push_back(i);
	    }
	    for(int i=0;i<result.size();i++){
	        cout<<result[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
