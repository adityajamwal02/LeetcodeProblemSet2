/// Minimum Swaps To Make Identical Array

#include <bits/stdc++.h>
int minimumSwaps(vector<int>& A, vector<int>& B){
    int n=A.size(), result=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[A[i]]=i;
    }
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i] or i==mp[B[i]]) continue;
        int counter=0, j=i;
        while(!vis[j]){
            vis[j]=1;
            j=mp[B[j]];
            counter++;
        }
        result+=(counter-1);
    }
return result;
}
