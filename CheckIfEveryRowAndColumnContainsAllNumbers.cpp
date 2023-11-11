/*
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

Example 1:
Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

Example 2:
Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false
*/


class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix){
        int n=matrix.size();
        // Marking positive to negative (row)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int position=abs(matrix[i][j])-1;
                if(matrix[i][position]<0) return false;
                matrix[i][position]=-matrix[i][position];
            }
        }
        // Marking negative to positive (col)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int position=abs(matrix[j][i])-1;
                if(matrix[position][i]>0) return false;
                matrix[position][i]=abs(matrix[position][i]);
            }
        }
    return true;
    }
};
