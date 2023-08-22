/*
A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.
Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.

Example 1:
Input: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
Output: 10
Explanation: There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.

Example 2:
Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.

Example 3:
Input: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.
*/

class Solution {
public:
    int counter, maxi, wallCount, r, result;

    int dfs(int i, int j, int n, int m, unordered_set<int> &st, vector<vector<int>> &grid){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!=1){
            return 0;
        }
        int ans=0;
        if(i+1<n and grid[i+1][j]==0){
            st.insert((i+1)*m+j);
            ans++;
        }
        if(i-1>=0 and grid[i-1][j]==0){
            st.insert((i-1)*m+j);
            ans++;
        }
        if(j+1<m and grid[i][j+1]==0){
            st.insert(i*m+(j+1));
            ans++;
        }
        if(j-1>=0 and grid[i][j-1]==0){
            st.insert(i*m+(j-1));
            ans++;
        }
        grid[i][j]=counter;
        ans+=dfs(i+1,j,n,m,st,grid);
        ans+=dfs(i-1,j,n,m,st,grid);
        ans+=dfs(i,j+1,n,m,st,grid);
        ans+=dfs(i,j-1,n,m,st,grid);

    return ans;
    }


    int containVirus(vector<vector<int>>& grid) {
        // 0 -> uninfected cells, 1 -> infected, find all viral regions (connected components)
        // Keep track of unaffected cells and perimeter of area of virus
        // Add the parameter of the most disinfect (unaffected cells directly in contact).
        // Approach callsfor  greedy simulation, with each movement, virus moves by 1 cell in 4-directions
        int n=grid.size(), m=grid[0].size(), result=0;
        unordered_set<int> st;
        while(true){
            counter=2, maxi=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        st.clear();
                        int walls=dfs(i,j,n,m,st,grid);
                        if(st.size()>maxi){
                            maxi=st.size();
                            wallCount=walls;
                            r=counter;
                        }
                        counter++;
                    }
                }
            }
            if(maxi==0) break;
            result+=wallCount;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==r){
                        grid[i][j]=1e9;
                    }else if(grid[i][j]>1 and grid[i][j]!=1e9){
                        grid[i][j]=1;
                        if(i+1<n and !grid[i+1][j]) grid[i+1][j]=1;
                        if(i-1>=0 and !grid[i-1][j]) grid[i-1][j]=1;
                        if(j+1<m and !grid[i][j+1]) grid[i][j+1]=1;
                        if(j-1>=0 and !grid[i][j-1]) grid[i][j-1]=1;
                    }
                }
            }
        }
    return result;
    }
};
