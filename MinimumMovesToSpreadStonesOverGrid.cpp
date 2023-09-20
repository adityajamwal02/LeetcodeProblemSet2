/*
You are given a 0-indexed 2D integer matrix grid of size 3 * 3, representing the number of stones in each cell. The grid contains exactly 9 stones, and there can be multiple stones in a single cell.
In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.
Return the minimum number of moves required to place one stone in each cell.

Example 1:
Input: grid = [[1,1,0],[1,1,1],[1,2,1]]
Output: 3
Explanation: One possible sequence of moves to place one stone in each cell is:
1- Move one stone from cell (2,1) to cell (2,2).
2- Move one stone from cell (2,2) to cell (1,2).
3- Move one stone from cell (1,2) to cell (0,2).
In total, it takes 3 moves to place one stone in each cell of the grid.
It can be shown that 3 is the minimum number of moves required to place one stone in each cell.

Example 2:
Input: grid = [[1,3,0],[1,0,0],[1,0,3]]
Output: 4
Explanation: One possible sequence of moves to place one stone in each cell is:
1- Move one stone from cell (0,1) to cell (0,2).
2- Move one stone from cell (0,1) to cell (1,1).
3- Move one stone from cell (2,2) to cell (1,2).
4- Move one stone from cell (2,2) to cell (2,1).
In total, it takes 4 moves to place one stone in each cell of the grid.
It can be shown that 4 is the minimum number of moves required to place one stone in each cell
*/

class Solution {
public:
    int helper(vector<vector<int>> &grid){
        bool result=true;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]!=1){
                    result=false;
                    break;
                }
            }
        }
        if(result) return 0;
        int counter=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(grid[i][j]==0 and grid[k][l]>1){
                            grid[k][l]-=1;
                            grid[i][j]+=1;
                            int dist=abs(i-k)+abs(j-l);
                            counter=min(counter,dist+helper(grid));
                            grid[k][l]+=1;
                            grid[i][j]-=1;
                        }
                    }
                }
            }
        }
    return counter;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        return helper(grid);
    }
};
