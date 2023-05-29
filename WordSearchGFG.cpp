/*
Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.

Example 1
Input: board = {{a,g,b,c},{q,e,e,l},{g,b,k,s}},
word = "geeks"
Output: 1
Explanation: The board is-
a g b c
q e e l
g b k s
The letters which are used to make the
"geeks" are colored.

Example 2:
Input: board = {{a,b,c,e},{s,f,c,s},{a,d,e,e}},
word = "sabfs"
Output: 0
Explanation: The board is-
a b c e
s f c s
a d e e
Same letter can not be used twice hence ans is 0
Your Task:
You don't need to read or print anything. Your task is to complete the function isWordExist() which takes board and word as input parameter and returns boolean value true if word can be found otherwise returns false.

Expected Time Complexity: O(N * M * 4L) where N = No. of rows in board, M = No. of columns in board, L = Length of word
Expected Space Compelxity: O(L), L is length of word.

Constraints:
1 ≤ N, M ≤ 100
1 ≤ L ≤ N*M
*/

class Solution {
public:
    bool dfs(int i, int j, int n, int m, string word, vector<vector<bool>> &vis, vector<vector<char>> &board, int len){
        if(len==word.size()){
            return true;
        }
        vis[i][j]=true;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and board[nrow][ncol]==word[len] and !vis[nrow][ncol]){
                if(dfs(nrow,ncol,n,m,word,vis,board,len+1)) return true;
            }
        }
    return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,n,m,word,vis,board,1)) return true;
                }
            }
        }
    return false;
    }
};
