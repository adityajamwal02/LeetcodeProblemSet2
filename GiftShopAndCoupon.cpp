/// Codechef que: Gift Shop and coupon

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> nums(n);
	    for(int i=0;i<n;i++){
	        cin>>nums[i];
	    }
	    sort(nums.begin(),nums.end());
	    int count=0;
        for(int i=0;i<n;i++){
	        if(k>=nums[i]){
	            k=k-nums[i];
	            count++;
	        }
	        else{
	            if(k>=(nums[i]+1)/2){
	                count++;
	                break;
	            }
	        }
	    }
        cout<<count<<endl;
	}
	return 0;
}


