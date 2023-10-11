/*
You are given an m x n binary matrix grid.
A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
Return the highest possible score after making any number of moves (including zero moves).

Example 1:
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Example 2:
Input: grid = [[0]]
Output: 1
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid){
        int n=grid.size(), m=grid[0].size(), result=0;
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            int count0=0, count1=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0) count0++;
                else count1++;
            }
            if(count0>count1){
                for(int i=0;i<n;i++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            int x=1;
            for(int j=m-1;j>=0;j--){
                result+=(grid[i][j])*x;
                x*=2;
            }
        }
    return result;
    }
};
