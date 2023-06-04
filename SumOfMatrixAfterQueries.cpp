/*
You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].
Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:
if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
Return the sum of integers in the matrix after all queries are applied.

Example 1:
Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
Output: 23
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23.

Example 2:
Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
Output: 17
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
*/

/// Solution 1 (TLE)

    vector<vector<int>> mat(n,vector<int>(n,0));
    for(auto q : queries){
        int flag=q[0], x=q[1], val=q[2];
        if(flag==0){
            for(int i=0;i<n;i++){
                mat[x][i]=val;
            }
        }else{
            for(int i=0;i<n;i++){
                mat[i][x]=val;
            }
        }
    }
    long long result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result+=(mat[i][j]);
        }
    }
    return result;
    }


/// Solution 2 : Accepted (SET + REVERSE LOGIC)

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sz=queries.size(), result=0;
        unordered_set<int> row, col;
        int currRow=n, currCol=n;
        for(int i=sz-1;i>=0;i--){
            int type=queries[i][0];
            int index=queries[i][1];
            int val=queries[i][2];
            if(type==0){
                if(row.count(index)) continue;
                row.insert(index);
                result+=(1LL)*(currRow)*(1LL)*val;
                currCol--;
            }else{
                if(col.count(index)) continue;
                col.insert(index);
                result+=(1LL)*(currCol)*(1LL)*val;
                currRow--;
            }
        }
    return result;
    }
};



