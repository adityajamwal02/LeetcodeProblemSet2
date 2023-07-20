/*

*/


/// Hashmap Solution

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long n=a.size();
    unordered_map<long long, long long> mp;
    long long currSum=0, result=0;
    for(long long i=0;i<n;i++){
        currSum+=a[i];
        if(currSum==k){
            result=max(result,i+1);
        }
        if(mp.find(currSum-k)!=mp.end()){
            long long len=i-mp[currSum-k];
            result=max(result,len);
        }
        if(mp.find(currSum)==mp.end()){
            mp[currSum]=i;
        }
    }
    return result;
}

/// 2 pointers Solution


#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long currSum=a[0];
    int i=0, j=0, result=0, n=a.size();
    while(j<n){
        while(i<=j and currSum>k){
            currSum-=a[i];
            i++;
        }
        if(currSum==k){
            result=max(result,j-i+1);
        }
        j++;
        if(j<n) currSum+=a[j];
    }
return result;
}
