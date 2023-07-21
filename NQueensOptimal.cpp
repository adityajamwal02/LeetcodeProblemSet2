/// N Queens :

#include<bits/stdc++.h>
using namespace std;

void solve(int col, int n,vector<vector<int>>&result, vector<int>&board, vector<int>&left, vector<int>&lower, vector<int>&upper ){
    if(col == n) {
        result.push_back(board);
        return;
    }
    for(int row = 0; row < n; row++){
        if(left[row] == 0 && lower[row + col] == 0 && upper[n-1+col-row] == 0){
            board[(n * row) + col] = 1; // to get the element index
            left[row] = 1;
            upper[n-1 + col - row] = 1;
            lower[col + row] = 1;
            solve(col+1, n, result, board, left, lower, upper);
            //back track
            board[n * row + col] = 0;
            left[row] = 0;
            upper[n-1 + col - row] = 0;
            lower[col + row] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> result;
    vector<int> board(n*n,0);
    vector<int> left(n,0); //left row
    vector<int> upper(2*n-1, 0); //upper diagonal... to check if marked check upper[n-1 + (col - row)]
    vector<int> lower(2*n-1, 0); // lower diagonal... to check if marked check lower[row + col]
    solve(0,n, result, board, left, lower, upper);
return result;
}
