/*
There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

Example 1:
Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.

Example 2:
Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.

Example 3:
Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
*/

class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    bool isPath(int n, int m, int mid, vector<vector<int>> &cells){
        vector<vector<bool>> grid(n,vector<bool>(m,0));
        for(int i=0;i<mid;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        queue<pair<int,int>> q;
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                q.push({0,j});
                grid[0][j]=1;
            }
        }
        while(!q.empty()){
            auto it = q.front();
            int i=it.first, j=it.second;
            q.pop();
            if(i==n-1) return true;
            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and grid[nrow][ncol]==0){
                    grid[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=1, high=cells.size(), result=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPath(row,col,mid,cells)){
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return  result;
    }
};
