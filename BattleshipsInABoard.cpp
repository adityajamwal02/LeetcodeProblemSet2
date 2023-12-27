/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.
Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

Example 1:
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2

Example 2:
Input: board = [["."]]
Output: 0
*/

class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    void dfs(int i, int j, int n, int m, vector<vector<char>> &board, vector<vector<bool>> &vis){
        if(board[i][j]!='X' or vis[i][j]) return;
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m){
                dfs(nrow,ncol,n,m,board,vis);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board){
        int n=board.size(), m=board[0].size(), counter=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    if(!vis[i][j]){
                        dfs(i,j,n,m,board,vis);
                        counter++;
                    }
                }
            }
        }
    return counter;
    }
};
