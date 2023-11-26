/*
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

Example 1:
Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.

Example 2:
Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.

Example 3:
Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
*/

/// Sort

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix){
        int n=matrix.size(), m=matrix[0].size(), result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0 and i>0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
            auto currRow=matrix[i];
            sort(currRow.rbegin(),currRow.rend());
            for(int row=0;row<m;row++){
                result=max(result,currRow[row]*(row+1));
            }
        }
    return result;
    }
};
