/*
You have got a maze, which is a n*n Grid. Every cell of the maze contains these numbers 1, 2 or 3.
If it contains 1 : means we can go Right from that cell only.
If it contains 2 : means we can go Down from that cell only.
If it contains 3 : means we can go Right and Down to both paths from that cell.
We cant go out of the maze at any time.
Initially, You are on the Top Left Corner of The maze(Entry). And, You need to go to the Bottom Right Corner of the Maze(Exit).
You need to find the total number of paths from Entry to Exit Point.
There may be many paths but you need to select that path which contains the maximum number of Adventure.
The Adventure on a path is calculated by taking the sum of all the cell values thatlies in the path.

Example 1:
Input: matrix = {{1,1,3,2,1},{3,2,2,1,2},
{1,3,3,1,3},{1,2,3,1,2},{1,1,1,3,1}}
Output: {4,18}
Explanation: There are total 4 Paths Available
out of which The Max Adventure is 18. Total
possible Adventures are 18,17,17,16. Of these
18 is the maximum.

Your Task:
You don't need to read or print anything. Your task is to complete the function FindWays() which takes matrix as input parameter and returns a list containg total number of ways to reach at (n, n) modulo 109 + 7 and maximum number of Adventure.

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)
*/

/// DP Solution


class Solution {
public:
int mod=1e9+7;

int helper(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i>=n or j>=n) return -1e8;
    if(i==n-1 and j==n-1) return mat[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    else{
        if(mat[i][j]==1) return dp[i][j]=1+helper(i,j+1,n,mat,dp);
        else if(mat[i][j]==2) return dp[i][j]=2+helper(i+1,j,n,mat,dp);
        else{
            int rWays=3+helper(i,j+1,n,mat,dp);
            int cWays=3+helper(i+1,j,n,mat,dp);
            return dp[i][j]=max(rWays,cWays);
        }
    }
}

int ways(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i>=n or j>=n) return 0;
    if(i==n-1 and j==n-1) return 1;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        if(mat[i][j]==1){
            return dp[i][j]=ways(i,j+1,n,mat,dp)%mod;
        }else if(mat[i][j]==2){
            return dp[i][j]=ways(i+1,j,n,mat,dp)%mod;
        }else{
            int rWays=ways(i,j+1,n,mat,dp)%mod;
            int cWays=ways(i+1,j,n,mat,dp)%mod;
            return dp[i][j]=(rWays+cWays)%mod;
        }
    }
}
vector<int> FindWays(vector<vector<int>>&mat){
    int n=mat.size();
    vector<vector<int>> dp1(n,vector<int>(n,-1));
    vector<vector<int>> dp2(n,vector<int>(n,-1));
    int counter=ways(0,0,n,mat,dp1);
    if(counter==0) return {0,0};
    int maxVal=helper(0,0,n,mat,dp2);
    return {counter,maxVal};
}
};
