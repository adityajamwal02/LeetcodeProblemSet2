/*
Let's play the minesweeper game (Wikipedia, online game)!
You are given an m x n char matrix board representing the game board where:
'M' represents an unrevealed mine,
'E' represents an unrevealed empty square,
'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
'X' represents a revealed mine.
You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').
Return the board after revealing this position according to the following rules:

If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.

Example 1:
Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]

Example 2:
Input: board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
Output: [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
*/

class Solution {
public:
    /* M -> unrevealed mine, E -> Empty sq, B -> Blank, X -> revealed mine
    */
    int delrow[8]={-1,-1,-1,0,0,1,1,1};
    int delcol[8]={-1,0,1,-1,1,-1,0,1};

    void dfs(int i, int j, int n, int m, vector<vector<char>> &board, vector<vector<int>> &bomb){
        if(bomb[i][j]==0) board[i][j]='B';
        else{
            board[i][j]=bomb[i][j]+'0';
            return;
        }
        for(int k=0;k<8;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and board[nrow][ncol]=='E'){
                dfs(nrow,ncol,n,m,board,bomb);
            }
        }
    }

    void bfs(int i, int j, int n, int m, vector<vector<int>> &bomb){
        for(int k=0;k<8;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                bomb[nrow][ncol]++;
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click){
        int n=board.size(), m=board[0].size();
        vector<vector<int>> bomb(n,vector<int>(m,0));
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]]='X';
            return board;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='M'){
                    bfs(i,j,n,m,bomb);
                }
            }
        }
        dfs(click[0],click[1],n,m,board,bomb);

    return board;
    }
};
