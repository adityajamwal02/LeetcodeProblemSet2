/*
Given an m x n binary matrix mat, return the number of special positions in mat.
A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

Example 1:
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

Example 2:
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
*/

class Solution {
public:
    bool check(int i, int j, int n, int m, vector<vector<int>> &mat){
        for(int col=0;col<m;col++){
            if(col==j) continue;
            if(mat[i][col]!=0) return false;
        }
        for(int row=0;row<n;row++){
            if(row==i) continue;
            if(mat[row][j]!=0) return false;
        }
    return true;
    }

    int numSpecial(vector<vector<int>>& mat){
        int n=mat.size(), m=mat[0].size(), counter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 and check(i,j,n,m,mat)){
                    counter++;
                }
            }
        }
    return counter;
    }
};
