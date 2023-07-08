/// 1760 Leetcode


#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int mid){
    int ops=0;
    for(int i=0;i<n;i++){
        ops+=arr[i]/mid;
        if(arr[i]%mid==0){
            ops--;
        }
    }
    if(ops<=m) return true;
    return false;
}

int minCountOfBallsInBag(vector<int> &arr, int n, int m)
{
    int low=1, high=*max_element(arr.begin(),arr.end());
    int result=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isValid(arr,n,m,mid)){
            result=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return result;
}
