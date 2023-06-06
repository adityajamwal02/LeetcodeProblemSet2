#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> result;
    int flag=1;
    while(flag){
        result.push_back(n);
        if(flag==0) break;
        if(n&(n-1)==0) n/=2;
        else n=(n*3 + 1);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
