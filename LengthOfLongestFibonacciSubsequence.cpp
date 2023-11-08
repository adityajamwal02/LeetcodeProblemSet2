/*
A sequence x1, x2, ..., xn is Fibonacci-like if:
n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

Example 1:
Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].

Example 2:
Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
*/

class Solution {
public:
    int helper(int i, int j, vector<int> &arr, unordered_map<int,int> &mp, vector<vector<int>> &dp){
        int curr=arr[i]+arr[j];
        if(dp[i][j]!=-1) return dp[i][j];
        if(mp.find(curr)==mp.end()) return dp[i][j]=2;
    return dp[i][j]=1+helper(j,mp[curr],arr,mp,dp);
    }

    int lenLongestFibSubseq(vector<int>& arr){
        int n=arr.size(), result=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                result=max(result,helper(i,j,arr,mp,dp));
            }
        }
    return result>=3 ? result : 0;
    }
};