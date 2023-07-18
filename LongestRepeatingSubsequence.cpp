/*
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Example 1:
Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y
0 1 2 3 4 5

The longest subsequence is "xx".
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str

We are able to use character 'x'
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A
and index 0 in subsequence B.
Example 2:
Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y
0 1 2 3 4

The longest subsequence is "xx".
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str

subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str

We are able to use character 'x'
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A
and index 0 in subsequence B.
*/

/// On basis of LCS

/// Memoization Code:

 int helper(int i, int j, string &str, vector<vector<int>> &dp){
	        if(i<0 or j<0) return 0;
	        if(dp[i][j]!=-1) return dp[i][j];
            int ans=0;
            if(str[i]==str[j] and i!=j){
	            ans=1+helper(i-1,j-1,str,dp);
	        }else{
    	        ans=max(helper(i-1,j,str,dp),helper(i,j-1,str,dp));
	        }
	    return dp[i][j]=ans;
	    }

		int LongestRepeatingSubsequence(string str){
		    int n=str.size();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

		return helper(n-1,n-1,str,dp);
		}

/// Tabulation Code :

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.size();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(str[i-1]==str[j-1] and i!=j){
		                dp[i][j]=1+dp[i-1][j-1];
		            }else{
		                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		            }
		        }
		    }
		return dp[n][n];
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
