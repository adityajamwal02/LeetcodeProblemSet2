/// Largest Family : Problem Code: LARGEFAM : Codechef

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
        sort(arr.begin(),arr.end());
        int result=0, sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum<=n-1) result++;
        }
    cout<<result<<endl;
    }
	return 0;
}
