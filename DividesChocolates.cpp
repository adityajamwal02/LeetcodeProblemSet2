/// Divides Chocolates

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int k, int n, int mid){
    int pieces=0, currSum=0;
    for(int i=0;i<n;i++){
        if(currSum+arr[i]>=mid){
            pieces++;
            currSum=0;
        }else{
            currSum+=arr[i];
        }
    }

return pieces>=k;
}

int getMaximumSweetness(vector<int> &arr, int k)
{
    if(k+1>arr.size()) return 0;
    // max of min
    int n=arr.size();
    int low=*min_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int result=low;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isValid(arr,k+1,n,mid)){
            result=mid;
            low=mid+1;
        }else {
            high=mid-1;
        }
    }
return result;
}

