/*
Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

Example 1:


Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
Example 2:


Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.
Example 3:


Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.

*/

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n=moves.size();
        // Player 1 -> Even index (0,2,4...)
        // Player 2 -> Odd Index (1,3,5...)
        vector<vector<char>> mat(3,vector<char>(3,' '));
        for(int i=0;i<n;i++){
            if(i%2==0){
                char ch='X'; // Player 1
                int row=moves[i][0], col=moves[i][1];
                mat[row][col]=ch;
            }else{
                char ch='O'; // Player 2
                int row=moves[i][0], col=moves[i][1];
                mat[row][col]=ch;
            }
        }
        // Horizontal Lines Check
        for(int i=0;i<3;i++){
            char ch=mat[i][0];
            int counter=0;
            for(int j=0;j<3;j++){
                if(ch!=mat[i][j]) break;
                else if(ch==mat[i][j]) counter++;
            }
            if(counter==3 and ch=='X') return "A";
            else if(counter==3 and ch=='O') return "B";
        }
        // Vertical Lines Check
        for(int j=0;j<3;j++){
            char ch=mat[0][j];
            int counter=0;
            for(int i=0;i<3;i++){
                if(ch!=mat[i][j]) break;
                else if(ch==mat[i][j]) counter++;
            }
            if(counter==3 and ch=='X') return "A";
            else if(counter==3 and ch=='O') return "B";
        }
        // Diagnol Check
        char ch=mat[0][0];
        int counter=0;
        for(int i=0;i<3;i++){
            if(ch==mat[i][i]) counter++;
            else break;
        }
        if(counter==3 and ch=='X') return "A";
        else if(counter==3 and ch=='O') return "B";

        // Other Daignol Check
        ch=mat[0][2];
        counter=0;
        for(int i=0;i<3;i++){
            if(ch==mat[i][3-i-1]) counter++;
            else break;
        }
        if(counter==3 and ch=='X') return "A";
        else if(counter==3 and ch=='O') return "B";

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(mat[i][j]==' ') return "Pending";
            }
        }
    return "Draw";
    }
};
