// Cost to Cut a Chocolate

#include <bits/stdc++.h>
using namespace std;

int cost(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin(),0);
    cuts.insert(cuts.end(),n);
    sort(cuts.begin(),cuts.end());
    int m=cuts.size();
    vector<vector<int>> dp(m,vector<int>(m,0));
    for(int i=m-1;i>=1;i--){
        for(int j=i;j<m-1;j++){
            int minCost=1e9;
            for(int k=i;k<=j;k++){
                int cost=(cuts[j+1]-cuts[i-1])+dp[i][k-1]+dp[k+1][j];
                minCost=min(minCost,cost);
            }
        dp[i][j]=minCost;
        }
    }
return dp[1][m-2];
}
