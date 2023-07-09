/*
Given an integer array nums and an integer k, return the number of subarrays where the number of
different integers in that array is at most k distinct values/ integers.
*/

#include <bits/stdc++.h>
using namespace std;

int kDistinctSubarrays(vector<int> &arr, int n, int k){
    unordered_map<int,int> mp;
    int i=0, j=0, result=0;
    while(j<n){
        mp[arr[j]]++;
        if(mp.size()>k){
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
            i++;
            }
        }
    result+=(j-i+1);
    j++;
    }
return result;
}
