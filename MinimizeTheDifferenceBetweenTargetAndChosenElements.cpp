/*
You are given an m x n integer matrix mat and an integer target.
Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.
Return the minimum absolute difference.
The absolute difference between two numbers a and b is the absolute value of a - b.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
Output: 0
Explanation: One possible choice is to:
- Choose 1 from the first row.
- Choose 5 from the second row.
- Choose 7 from the third row.
The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.

Example 2:
Input: mat = [[1],[2],[3]], target = 100
Output: 94
Explanation: The best possible choice is to:
- Choose 1 from the first row.
- Choose 2 from the second row.
- Choose 3 from the third row.
The sum of the chosen elements is 6, and the absolute difference is 94.

Example 3:
Input: mat = [[1,2,9,8,7]], target = 6
Output: 1
Explanation: The best choice is to choose 7 from the first row.
The absolute difference is 1.
*/

class Solution {
public:
    int dp[71][5000];

    int helper(int i, int sum, int n, int m, vector<vector<int>> &mat, int target){
        if(i>=n) return abs(target-sum);
        if(dp[i][sum]!=-1) return dp[i][sum];
        int result=INT_MAX;
        for(int j=0;j<m;j++){
            result=min(result,helper(i+1,sum+mat[i][j],n,m,mat,target));
            if(result==0) break;
        }
    return dp[i][sum]=result;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target){
        int n=mat.size(), m=mat[0].size();
        memset(dp,-1,sizeof(dp));

    return helper(0,0,n,m,mat,target);
    }
};
