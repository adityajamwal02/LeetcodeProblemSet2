/*
You are given an m x n integer matrix grid.
We define an hourglass as a part of the matrix with the following form:
Return the maximum sum of the elements of an hourglass.
Note that an hourglass cannot be rotated and must be entirely contained within the matrix.

Example 1:
Input: grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
Output: 30
Explanation: The cells shown above represent the hourglass with the maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.

Example 2:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 35
Explanation: There is only one hourglass in the matrix, with the sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.
*/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid){
        int n=grid.size(), m=grid[0].size(), result=INT_MIN;
        vector<vector<long long>> prefixSum(n,vector<long long>(m,0));
        prefixSum[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            prefixSum[i][0]=prefixSum[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            prefixSum[0][i]=prefixSum[0][i-1]+grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                prefixSum[i][j]=prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1]+grid[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>1 and j>1){
                    int currSum=prefixSum[i][j];
                    if(i>2) currSum-=prefixSum[i-3][j];
                    if(j>2) currSum-=prefixSum[i][j-3];
                    if(i>2 and j-2) currSum+=prefixSum[i-3][j-3];
                    result=max(result,currSum-grid[i-1][j-2]-grid[i-1][j]);
                }
            }
        }
    return result;
    }
};
