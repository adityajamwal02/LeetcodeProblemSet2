/// Problem Code: NODRUGS  : Say No To Drugs


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k, l;
        cin>>n>>k>>l;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // Friend -> n-1
        int maxSpeed=*max_element(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(maxSpeed==arr[i]){
                count++;
            }
        }
        if(k<0 and arr[n-1]!=maxSpeed){
            cout<<"NO"<<endl;
        }
        else if(arr[n-1]==maxSpeed and count<=1){
            cout<<"YES"<<endl;
        }else if(arr[n-1]==maxSpeed and count>1){
            cout<<"NO"<<endl;
        }else{
            int maxAdd=(l-1)*k;
            if(maxAdd+arr[n-1]>maxSpeed){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
	return 0;
}
