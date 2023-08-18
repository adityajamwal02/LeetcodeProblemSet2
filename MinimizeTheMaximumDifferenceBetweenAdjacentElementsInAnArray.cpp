/// Minimize the maximum difference between adjacent elements in an array

#include <bits/stdc++.h>
using namespace std;

int findMinAnswer(vector<int> &diff, int k){
    int n=diff.size();
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() and diff[i]>=diff[dq.back()]){
            dq.pop_back();
        }
    dq.push_back(i);
    }
    int result=diff[dq.front()];
    for(int i=k;i<n;i++){
        if(!dq.empty() and dq.front()==(i-k)){
            dq.pop_front();
        }
        while(!dq.empty() and diff[i]>=diff[dq.back()]){
            dq.pop_back();
        }
    dq.push_back(i);
    result=min(result,diff[dq.front()]);
    }
return result;
}

int maxAdjDifference(vector<int> &arr, int k){
    int n=arr.size();
    vector<int> diff(n-1);
    for(int i=0;i<n-1;i++){
        diff[i]=arr[i+1]-arr[i];
    }
return findMinAnswer(diff,n-k-1);
}

