/// Ball Distribution : Codechef

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    int currSum=0;
	    vector<int> arr(m);
	    for(int i=0;i<m;i++){
	        cin>>arr[i];
	        currSum+=arr[i];
	    }
	    int result=n*(m-1);
	    if((currSum-result)<0) cout<<0<<endl;
	    else cout<<(currSum-result)<<endl;
	}
	return 0;
}

