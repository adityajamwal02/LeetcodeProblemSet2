/// Equal Candies : Coding Ninjas


#include <bits/stdc++.h>
long long int equalCandies (vector<int> &candies, int n)
{
	sort(candies.begin(),candies.end());
	long long median=candies[n/2];
	long long counter=0;
	if(n==1){
		return 0;
	}else{
		for(int i=0;i<n;i++){
			counter+=(abs(median-candies[i]));
		}
	}
return counter;
}
