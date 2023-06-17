/*
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
If there is no way to make arr1 strictly increasing, return -1.

Example 1:
Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

Example 2:
Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Example 3:
Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
*/

/// Recursion

class Solution {
public:
    int solve(int i, int j, int &n, int &m, int prev, vector<int> &arr1, vector<int> &arr2){
        if(i==n) return 0;
        j=upper_bound(arr2.begin()+j,arr2.end(),prev)-arr2.begin();
        if(j==m and arr1[i]<=prev) return 2001;
        int take=2001, notTake=2001;
        if(j!=m){
            take=1+solve(i+1,j+1,n,m,arr2[j],arr1,arr2);
        }
        if(arr1[i]>prev){
            notTake=solve(i+1,j,n,m,arr1[i],arr1,arr2);
        }
    return min(take,notTake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(), m=arr2.size();
        sort(arr2.begin(),arr2.end());
        int result=solve(0,0,n,m,-1,arr1,arr2);
    return (result>n) ? -1 : result;
    }
};

/// Memoization

class Solution {
public:
    int solve(int i, int j, int &n, int &m, int prev, vector<int> &arr1, vector<int> &arr2, vector<vector<int>> &dp){
        if(i==n) return 0;
        j=upper_bound(arr2.begin()+j,arr2.end(),prev)-arr2.begin();
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==m and arr1[i]<=prev) return 2001;
        int take=2001, notTake=2001;
        if(j!=m){
            take=1+solve(i+1,j+1,n,m,arr2[j],arr1,arr2,dp);
        }
        if(arr1[i]>prev){
            notTake=solve(i+1,j,n,m,arr1[i],arr1,arr2,dp);
        }
    return dp[i][j]=min(take,notTake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(), m=arr2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        sort(arr2.begin(),arr2.end());
        int result=solve(0,0,n,m,-1,arr1,arr2,dp);
    return (result>n) ? -1 : result;
    }
};
