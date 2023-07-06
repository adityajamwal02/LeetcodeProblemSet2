/*
Given string s consisting only a,b,c. return the number of substrings containing at least one occurrence of all these characters a, b, and c.

Example 1:

Input:
abcabc
Output:
10
Explanation:
The required substrings  are "abc", "abca", "abcab", "abcabc",
"bca", "bcab", "bcabc", "cab", "cabc" and "abc".

Example 2:

Input:
aaacb
Output:
3
Your Task:
You don't have to read input or print anything. Your task is to complete the function countSubstring() which takes the string s and returns the count of substring having at least a,b,c.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int helper(string s, int k){
        int i=0, j=0, counter=0, n=s.size();
        unordered_map<int,int> mp;
        while(j<n){
            mp[s[j]]++;
            while(i<=j and mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
            i++;
            }
            counter+=(j-i+1);
        j++;
        }
    return counter;
    }

    int countSubstring(string s) {
        return helper(s,3)-helper(s,2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
