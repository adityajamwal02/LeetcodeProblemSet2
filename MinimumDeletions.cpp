/*
Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:
Input:
S = "aebcbda"
Output:
2
Explanation:
Remove characters 'e' and 'd'.

Example 2:
Input:
S = "geeksforgeeks"
Output:
8
Explanation:
One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:

    int LCS(string &s, string &t){
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    return dp[n][n];
    }

    int LPS(string s){
        string t=s;
        reverse(t.begin(),t.end());
    return LCS(s,t);
    }

    int minimumNumberOfDeletions(string S) {
        int n=S.size();
    return n-LPS(S);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
