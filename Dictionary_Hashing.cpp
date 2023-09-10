/// Hashing

#include<bits/stdc++.h>
using namespace std;

// Such hashfunctions have better lookups than b-trees with TC O(1)

int hashFunc(string &s, int n){
    int result=0;
    for(int i=0;i<n;i++){
        result+=(int)(s[i]-'a'+1);
    }
return result;
}

// Approach not efficient for tolerant retrievals : Prefix Search

int main(){
    string str;
    cin>>str;
    int n=str.size();
    int result=hashFunc(str,n);
    cout<<result<<endl;

    return 0;
}
