/// Divisible subset

#include<bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &arr){
    int n=arr.size(), maxi=1, lastIndex=0;
    vector<int> dp(n,1), result(n);
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        result[i]=i;
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 and dp[i]<1+dp[j]){
                dp[i]=1+dp[j];
                result[i]=j;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while(result[lastIndex]!=lastIndex){
        lastIndex=result[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
