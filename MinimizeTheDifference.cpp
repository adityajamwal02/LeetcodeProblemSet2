/// Minimize The Difference

#include <bits/stdc++.h>
int minimizeIt(vector<int> A, int k)
{
	int n=A.size();
	sort(A.begin(),A.end());
	int result=A[n-1]-A[0];
	int mini=A[0], maxi=A[n-1];
	for(int i=1;i<n;i++){
		if(A[i]-k<0) continue;
		mini=min(A[0]+k,A[i]-k);
		maxi=max(A[n-1]-k,A[i-1]+k);
	result=min(result,maxi-mini);
	}
return result;
}
