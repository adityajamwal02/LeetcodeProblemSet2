/// Codechef : Problem Code: MIXCOLOR


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        set<int> st(arr.begin(),arr.end());
        cout<<n-st.size()<<endl;
    }
	return 0;
}

