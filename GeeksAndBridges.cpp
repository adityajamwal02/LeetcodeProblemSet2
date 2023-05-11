/*
Geek wants to build bridges between two banks of a river to help migrants to reach their homes. But, he can build a bridge only between two similar posts. Bridges can't overlap. The task is to find the maximum number of bridges geek can build.
Note: Each of the posts is represented by either '*' or '@' or '#'.
Example: Let str1 = "*@#*", str2 = "*#". Then output will be 2.
* @ # *
|     /
*  #
Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space-separated strings representing the posts in each bank

Output: For each test case, print the maximum number of bridges geek can build.
Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 100

Example:
Input:
2
*@#* *#
*** ##

Output:
2
0
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m, string &a, string &b, vector<vector<int>> &dp){
    if(i==n or j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]){
        return dp[i][j]=1+solve(i+1,j+1,n,m,a,b,dp);
    }else{
        return dp[i][j]=max(solve(i,j+1,n,m,a,b,dp),solve(i+1,j,n,m,a,b,dp));
    }
}

int maxUncrossedLines(string &a, string &b){
    int n=a.size(), m=b.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(0,0,n,m,a,b,dp);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string a, b;
	    cin>>a>>b;
	    int temp=maxUncrossedLines(a,b);
	    cout<<temp<<endl;
	}
	return 0;
}
