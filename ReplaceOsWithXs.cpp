/*
Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'},
               {'X', 'X', 'X', 'X'},
               {'X', 'X', 'X', 'X'},
               {'X', 'X', 'X', 'X'},
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above
matrix is the resultant matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes n, m and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
*/

// User function Template for C++

class Solution{
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};
    void dfs(int i, int j, int n, int m, vector<vector<int>> &vis, vector<vector<char>> mat){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and !vis[nrow][ncol] and mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,n,m,vis,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                     if(!vis[i][j] and mat[i][j]=='O'){
                         dfs(i,j,n,m,vis,mat);
                     }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
    return mat;
    }
};
