/*
More formally, for a given array A and an integer X, check whether the array can be sorted in increasing order by reversing some
(possibly none) of the subarrays such that the sum of all elements of the subarray is at most X.
*/

/// Codechef Problem Code: REVSORT

#include <bits/stdc++.h>
using namespace std;

bool bubbleSort(vector<int> arr, int n, int x){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            if(arr[i]+arr[i+1]<=x){
                swap(arr[i],arr[i+1]);
            }else{
                return false;
            }
        }
    }
    return true;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    vector<int> nums(n);
	    for(int i=0;i<n;i++){
	        cin>>nums[i];
	    }
	    if(bubbleSort(nums,n,x)){
	        cout<<"YES"<<endl;
	    }else cout<<"NO"<<endl;
	}
	return 0;
}
