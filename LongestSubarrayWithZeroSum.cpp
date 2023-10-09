/// Longest Subarray With Zero Sum


#include<bits/stdc++.h>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int n=arr.size(), result=0, currSum=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		currSum+=arr[i];
		if(currSum==0){
			result=i+1;
		}else{
			if(mp.find(currSum)!=mp.end()){
				result=max(result,i-mp[currSum]);
			}else{
				mp[currSum]=i;
			}
		}
	}
return result;
}
