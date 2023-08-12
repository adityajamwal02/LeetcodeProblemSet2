/// Anshika Que1. Number line : Initial thought : DP based

#include<bits/stdc++.h>
using namespace std;

int helper(int i, int n, int jump){
    if(i==0) return 0;
    if(i==n) return 1;

    int take=abs(i-jump)+helper(i+jump,n,jump+1);
    int revTake=INT_MAX;
    if(i-jump>0){
        revTake=abs(i-jump)+helper(i-jump,n,jump+1);
    }
    return min(take,revTake);
}

int getMinCost(int n){
    return helper(n,2*n,1);
}

int main(){
    int n;
    cin>>n;
    int result=getMinCost(n);
    cout<<result<<endl;

    return 0;
}
