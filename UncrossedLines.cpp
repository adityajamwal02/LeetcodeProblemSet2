/*
You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
Return the maximum number of connecting lines we can draw in this way.

Example 1:
Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.

Example 2:
Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3

Example 3:
Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2
*/

/// Recursion

class Solution {
public:
    int solve(int i, int j, int n, int m, vector<int> &nums1, vector<int> &nums2){
        if(i==n or j==m){
            return 0;
        }
        if(nums1[i]==nums2[j]){
            return 1+solve(i+1,j+1,n,m,nums1,nums2);
        }else{
            return max(solve(i,j+1,n,m,nums1,nums2),solve(i+1,j,n,m,nums1,nums2));
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
    return solve(0,0,n,m,nums1,nums2);
    }
};


/// Memoization

class Solution {
public:
    int solve(int i, int j, int n, int m, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        if(i==n or j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+solve(i+1,j+1,n,m,nums1,nums2,dp);
        }else{
            return dp[i][j]=max(solve(i,j+1,n,m,nums1,nums2,dp),solve(i+1,j,n,m,nums1,nums2,dp));
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
    return solve(0,0,n,m,nums1,nums2,dp);
    }
};


/// Tabulation

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<n+1;i++){
           for(int j=1;j<m+1;j++){
               //if(i==0 or j==0) dp[i][j]=0;
               if(nums1[i-1]==nums2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               }
           }
        }
    return dp[n][m];
    }
};
