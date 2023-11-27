/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.
To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
Return the maximum number of points you can achieve.
abs(x) is defined as:
x for x >= 0.
-x for x < 0.

Example 1:
Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.

Example 2:
Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
*/

/// Memoization

class Solution {
public:
    long long helper(int i, int j, int n, int m, vector<vector<int>> &points, vector<vector<long long>> &dp){
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long result=0;
        for(int col=0;col<m;col++){
            result=max(result,points[i][col]-abs(col-j)+helper(i+1,col,n,m,points,dp));
        }
    return dp[i][j]=result;
    }

    long long maxPoints(vector<vector<int>>& points){
        int n=points.size(), m=points[0].size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        long long maxVal=0;
        for(int i=0;i<m;i++){
            maxVal=max(maxVal,helper(1,i,n,m,points,dp)+points[0][i]);
        }
    return maxVal;
    }
};

/// Tabulation

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points){
        int n=points.size(), m=points[0].size();
        vector<long long> result(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<points[i].size();j++){
                result[j]+=points[i][j];
                if(j>0) result[j]=max(result[j],result[j-1]-1);
            }
            for(int j=points[i].size()-2;j>=0;j--){
                result[j]=max(result[j],result[j+1]-1);
            }
        }
    return *max_element(result.begin(),result.end());
    }
};
