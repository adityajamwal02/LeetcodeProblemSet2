/// Max Mex : Codechef : Problem Code: MEX


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int counter=-1;
        for(int i=0;i<n;i++){
            if(counter<arr[i]-1){
                if(k>0){
                    while(counter<arr[i]-1 and k>0){
                        counter++;
                        k--;
                    }
                }else break;
            }
            if(counter==arr[i]-1){
                counter++;
            }
        }
        cout<<(counter+k+1)<<endl;
    }
	return 0;
}
