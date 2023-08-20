/// Given

#include<bits/stdc++.h>
using namespace std;

int helper(int ind , int n , int p , vector<int>& milk , vector<int>& apples , vector<vector<int>>& dp)
{   if(ind == n) return 0;
    if(p <= 0) return 0;
    if(dp[ind][p] != -1) return dp[ind][p];
    int ans1 = 0 , ans2 = 0;
    if(p <= n - ind){
        ans1 = apples[ind] + helper(ind + 1 , n , p - 1 , milk , apples , dp);
        ans2 = helper(ind + 1 , n , p + milk[ind] - 1 , milk , apples ,dp);
    }else ans1 = apples[ind] + helper(ind + 1 , n , p - 1 , milk , apples , dp);

    return dp[ind][p] = max(ans1 , ans2);
}

int solve(){
    int n ;
    long long int p;
    cin >> n >> p;
    vector<int>milk(n) , apples(n);
    for(int i = 0 ; i < n ; i++)
        cin >> milk[i];
    for(int i = 0 ; i < n ; i++)
        cin >> apples[i];
    long long int sum = accumulate(apples.begin() , apples.end() , 0LL);
    if(p >= n) return sum;
    vector<vector<int>>dp(n , vector<int>(2000 , -1));
    return helper(0 , n , p , milk , apples , dp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cout<<solve()<<endl;
    }
return 0;
}
