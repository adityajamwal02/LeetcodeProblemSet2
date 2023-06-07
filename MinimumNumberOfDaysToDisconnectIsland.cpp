/*
You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.

Example 1:
Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Example 2:
Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
*/

///DFS (IDEA: If components > 1 ,already disconnected: return 0 , if articulation point present (tarjan's algo) return 1 , else all other cases return 2)


class Solution {
private:
    // helper function to check if the given row and column indices are within the bounds of the grid
    bool isInBounds(int row, int col, int totalRows, int totalCols) {
        return row >= 0 && row < totalRows && col >= 0 && col < totalCols;
    }

    // Depth-First Search function to identify the articulation points in the grid
    // An articulation point is a cell that, when removed, disconnects the grid
    void dfsArticulationPoint(int row, int col, int parentRow, int parentCol, vector<vector<int>>& insertionTime, vector<vector<int>>& lowestTime, bool& containsArticulationPoint, int& timer,
                                vector<vector<bool>>& visited, vector<vector<int>>& grid, vector<int>& dRow, vector<int>& dCol) {
        // mark the current cell as visited
        visited[row][col] = true;

        // set the insertion time and lowest time of the current cell as the current timer value
        insertionTime[row][col] = lowestTime[row][col] = timer++;

        // variable to store the number of child components (connected 1s) of the current cell
        int childComponents = 0;

        // iterate through the 4 directions (left, right, up, down) to visit the neighbours
        for(int direction = 0; direction < 4; direction++) {
            int neighbourRow = row + dRow[direction];
            int neighbourCol = col + dCol[direction];

            // skip the parent cell, as it is not a neighbour
            if(neighbourRow == parentRow && neighbourCol == parentCol) continue;

            // if the neighbour cell is within the bounds of the grid and is a land cell (has a value of 1)
            if(isInBounds(neighbourRow, neighbourCol, grid.size(), grid[0].size()) && grid[neighbourRow][neighbourCol] == 1) {

                // if the neighbour has not been visited yet
                if(!visited[neighbourRow][neighbourCol]) {

                    // recursively call the DFS function on the neighbour
                    dfsArticulationPoint(neighbourRow, neighbourCol, row, col, insertionTime, lowestTime, containsArticulationPoint, timer, visited, grid, dRow, dCol);

                    // update the lowest time of the current cell with the minimum of its current lowest time and the lowest time of the neighbour
                    lowestTime[row][col] = min(lowestTime[row][col], lowestTime[neighbourRow][neighbourCol]);

                    // if the lowest time of the neighbour is greater than or equal to the insertion time of the current cell, and the current cell is not the root (has a parent)
                    if(lowestTime[neighbourRow][neighbourCol] >= insertionTime[row][col] && parentRow != -1 && parentCol != -1) {

                        // mark that the grid contains an articulation point
                        containsArticulationPoint = true;
                    }

                    // increment the number of child components of the current cell
                    childComponents++;
                } else {
                    // if the neighbour has already been visited, update the lowest time of the current cell
                    // with the minimum of its current lowest time and the insertion time of the neighbour
                    lowestTime[row][col] = min(lowestTime[row][col], insertionTime[neighbourRow][neighbourCol]);
                }
            }
        }

        // if the current cell has more than 1 child component and is the root (has no parent), mark that the grid contains an articulation point
        if(childComponents > 1 && parentRow == -1 && parentCol == -1) {
            containsArticulationPoint = true;
        }
    }

public:
    int minDays(vector<vector<int>>& grid) {
        // get the number of rows and columns in the grid
        int rows = grid.size();
        int cols = grid[0].size();

        // 2D vector to store the visited status of each cell
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // 2D vectors to store the insertion time and lowest time of each cell
        vector<vector<int>> insertionTime(rows, vector<int>(cols));
        vector<vector<int>> lowestTime(rows, vector<int>(cols));
        // variable to store whether the grid contains an articulation point
        bool containsArticulationPoint = false;
        // variable to store the timer value (incremented each time a cell is visited)
        int timer = 0;

        // vectors to store the row and column offsets to visit the neighbours in the 4 directions (left, right, up, down)
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};

        // variable to store the number of land cells (cells with a value of 1) in the grid
        int numberOfLandCells = 0;
        // variable to store the number of connected components (groups of connected 1s) in the grid
        int numberOfComponents = 0;

        // iterate through the grid to identify the articulation points and count the number of land cells and connected components
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                // if the current cell is a land cell
                if(grid[row][col] == 1) {
                    // increment the number of land cells
                    numberOfLandCells++;

                    // if the current cell has not been visited yet
                    if(!visited[row][col]) {
                        // perform DFS starting from the current cell to identify the articulation points and count the connected components
                        dfsArticulationPoint(row, col, -1, -1, insertionTime, lowestTime, containsArticulationPoint, timer, visited, grid, dRow, dCol);

                        // increment the number of connected components
                        numberOfComponents++;
                    }
                }
            }
        }

        // if the number of connected components is not 1, the grid is already disconnected, so return 0 days
        // otherwise, if the grid contains an articulation point or if there is only 1 land cell in the grid, return 1 day
        // otherwise, return 2 days
        return numberOfComponents != 1 ? 0 : containsArticulationPoint || numberOfLandCells == 1 ? 1 : 2;
    }
};
