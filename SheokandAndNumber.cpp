/// Codechef : Problem Code: SHKNUM , Sheokand and Number

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long n, sum=0, result=LLONG_MAX;
	    cin>>n;
	    vector<int> arr(32);
	    for(int i=0;i<32;i++){
	        arr[i]=pow(2,i);
	    }
	    for(int i=0;i<32;i++){
	        for(int j=i+1;j<32;j++){
	            sum=arr[i]+arr[j];
	            result=min(result,abs(sum-n));
	        }
	    }
	    cout<<result<<endl;
	}
	return 0;
}

