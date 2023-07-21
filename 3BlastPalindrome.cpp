/// 3 Blast Palindrome

#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n = 0;
    cin >> n;
    string string1;
    cin >> string1;
    if(n%3==1){
        cout<<"YES"<<endl;
        return;
    }
    if (n%3 == 2){
        vector<bool> temp(1000,false);
        for (int i = 0; i < n; i++){
            if (i%3 == 0){
                temp[string1[i]] = true;
                continue;
            }
            if(i%3 == 1 and temp[string1[i]]){
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
    vector<bool> has_0_come(1000,false);
    for (int i = 0; i < n; i++){
        if (i%3 == 0){
            has_0_come[ string1[i] ] = true;
            continue;
        }
        if (i%3 == 2 && has_0_come[string1[i]]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long  long  t = 0;cin>>t;
    while (t--){
        solve();
    }
}
