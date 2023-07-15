/// Covid Vaccination : Coding Ninjas


#include<bits/stdc++.h>
using namespace std;

int solve(int left, int right, int mid){
	int sum=mid*mid;
	if(mid-1>=left){
		int k=mid-1-left;
		sum-=(k*(k+1)/2);
	}else{
		sum+=left-mid+1;
	}
	if(mid-1>=right){
		int k=mid-1-right;
		sum-=(k*(k+1)/2);
	}else{
		sum+=right-mid+1;
	}
return sum;
}


int maxVaccinesAdministered(int n, int dayNumber, int maxVaccines)
{
	// n -> no. of vaccine days
	// dayNumber -> kth day at which maximum number of vaccines (used)
	// maxVaccines -> total numbe of vaccines present
	// Each day min. of 1 vaccine + abs(counti-countj)<=1 (1<=i<j=i+1), maxVaccines=total (high)
	// Maximize kth day vaccine

	int low=1, high=maxVaccines, left=dayNumber, right=n-1-dayNumber;
	while(low<=high){
		int mid=low+(high-low)/2;
		int result=solve(left,right,mid);
		if(result==maxVaccines){
			return mid;
		}else if(result<maxVaccines){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
return high;
}

