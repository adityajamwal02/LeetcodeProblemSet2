/// Cyclic Sort : VERY IMP

#include<bits/stdc++.h>
using namespace std;

void cyclicSort(vector<int> &arr, int n){
    int i=0;
    while(i<n){
        int correct=arr[i]-1;
        if(arr[i]!=arr[correct]){
            swap(arr[i],arr[correct]);
        }else{
            i++;
        }
    }
}

int main(){
    vector<int> arr={3, 2, 4, 3, 1, 9, 3, 8, 2, 8, 1, 3, 2, 2 ,2, 9, 5, 1};
    int n=arr.size();
    cout<<"BEFORE SORTING: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cyclicSort(arr,n);
    cout<<"AFTER SORTING: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}







/// Example workcase:

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0 and nums[i]<=nums.size() and nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
    return nums.size()+1;
    }
};
