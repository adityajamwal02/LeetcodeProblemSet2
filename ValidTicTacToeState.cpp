/*
Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.
Here are the rules of Tic-Tac-Toe:
Players take turns placing characters into empty squares ' '.
The first player always places 'X' characters, while the second player always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.

Example 1:
Input: board = ["O  ","   ","   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX"," X ","   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XOX","O O","XOX"]
Output: true
*/

class Solution {
public:
    bool check(char ch, vector<string> &s){
        for(int i=0;i<3;i++){
            if(s[i][0]==ch and s[i][0]==s[i][1] and s[i][1]==s[i][2]) return true;
            else if(s[0][i]==ch and s[0][i]==s[1][i] and s[1][i]==s[2][i]) return true;
        }
        if((s[0][0]==ch and s[0][0]==s[1][1] and s[1][1]==s[2][2]) or (s[0][2]==ch and s[0][2]==s[1][1] and s[1][1]==s[2][0])) return true;

    return false;
    }

    bool validTicTacToe(vector<string> &board){
        int n=board.size(), m=board[0].size(), zero=0, cross=0;
        if(check('X',board) and check('O',board)) return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') zero++;
                else if(board[i][j]=='X') cross++;
            }
        }
        if(zero>cross or cross-zero>1) return false;
        if(check('X',board) and zero==cross) return false;
        if(check('O',board) and zero!=cross) return false;

    return true;
    }
};
