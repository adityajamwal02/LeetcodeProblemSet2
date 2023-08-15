/*
We have an horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = size of the stations array. Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of D. Find the answer exactly to 2 decimal places.

Example 1:
Input:
N = 10
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
K = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.

Example 2:
Input:
N = 10
stations = [3,6,12,19,33,44,67,72,89,95]
K = 2
Output: 14.00
Explanation: Construction of gas stations at 86 locations

Your Task:
You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer K as inputs and returns the smallest possible value of D. Find the answer exactly to 2 decimal places.
Expected Time Complexity: O(N*log K)
Expected Auxiliary Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int numberOfGasStation(long double mid, vector<int> &arr){
	int counter=0;
	for(int i=1;i<arr.size();i++){
		int numberBetween=((arr[i]-arr[i-1])/mid);
		if((arr[i]-arr[i-1])/mid == numberBetween*mid){
			numberBetween--;
		}
	counter+=numberBetween;
	}
return counter;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	long double low=0, high=0, diff=1e-6;
	for(int i=0;i<arr.size()-1;i++){
		high=max(high,(long double)(arr[i+1]-arr[i]));
	}
	while(high-low>diff){
		long double mid=(low+high)/2.0;
		int counter=numberOfGasStation(mid,arr);
		if(counter>k) low=mid;
		else high=mid;
	}
return high;
}
