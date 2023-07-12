
/// Get All unique subsets : Coding ninjas


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void helper(int i, int n, vector<int> &arr, vector<int> temp){
    result.push_back(temp);
    for(int j=i;j<n;j++){
        if(j!=i and arr[j]==arr[j-1]) continue;
        temp.push_back(arr[j]);
        helper(j+1,n,arr,temp);
        temp.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    int n=arr.size();
    vector<int> temp;
    sort(arr.begin(),arr.end());
    helper(0,n,arr,temp);
return result;
}
