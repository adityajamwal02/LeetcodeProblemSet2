/// Magic Index : A[i]=i in sorted array

/// BS

#include <bits/stdc++.h>
int magicIndex(vector<int> a, int n) {
	long long int low=0, high=n-1;
	while(low<=high){
		long long int mid=(low+high)/2;
		if(a[mid]==mid) return mid;
		else if(a[mid]<mid){
			low=mid+1;
		}
		else if(a[mid]>mid){
			high=mid-1;
		}
	}
return -1;
}


/// LS


