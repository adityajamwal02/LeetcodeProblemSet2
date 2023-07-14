/// Sum of Infinite Array


#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

long long helper(vector<long long> &prefixSum, long long i, long long n){
    long long repeat=(i/n)%mod;
    long long sum=(repeat*prefixSum[n])%mod;
    sum=(sum+(prefixSum[i%n]))%mod;

return sum;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    vector<int> result;
    vector<long long> prefixSum(n+1,0);
    for(int i=1;i<=n;i++){
        prefixSum[i]=(arr[i-1]+prefixSum[i-1])%mod;
    }
    for(int i=0;i<q;i++){
        long long low=queries[i][0];
        long long high=queries[i][1];
        long long leftSum=helper(prefixSum,low-1,n);
        long long rightSum=helper(prefixSum,high,n);
    result.push_back((rightSum-leftSum+mod)%mod);
    }
return result;
}
