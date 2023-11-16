#include <bits/stdc++.h>
using namespace std;

unsigned long long counter=0;

void helper(string &str, int low, int high){
    if(low==high){
        cout<<str<<endl;
        counter++;
    }else{
        for(int i=low;i<=high;i++){
            swap(str[low],str[i]);
            helper(str, low+1, high);
            swap(str[low],str[i]);
        }
    }
}

int main(){
    string str="abcdefghijklmnopqrstuvwxyz";
    helper(str,0,str.size()-1);
    cout<<endl<<counter;

    return 0;
}
