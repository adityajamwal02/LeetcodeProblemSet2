///

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &stalls, int n, int c, int mid){
    int countCows=1, last=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-last>=mid){
            countCows++;
            last=stalls[i];
        }
        if(countCows>=c) return true;
    }
return false;
}
int solve(vector<int> &stalls, int n, int c){
    sort(stalls.begin(),stalls.end());
    int low=1, high=stalls[n-1]-stalls[0];
    int result=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isValid(stalls,n,c,mid)){
            result=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
return result;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        vector<int> stalls(n);
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        int result=solve(stalls,n,c);
        cout<<result<<endl;
    }
return 0;
}
