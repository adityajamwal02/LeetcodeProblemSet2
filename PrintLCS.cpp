/// Print Longest Common Subsequence


#include<bits/stdc++.h>
using namespace std;

string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int i=n, j=m;
	string result="";
	while(i>0 and j>0){
		if(s1[i-1]==s2[j-1]){
			result+=s1[i-1];
			i--;
			j--;
		}else{
			if(dp[i][j-1]>dp[i-1][j]){
				j--;
			}else{
				i--;
			}
		}
	}
	reverse(result.begin(),result.end());
return result;
}
