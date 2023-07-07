/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:
Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Example 2:
Input:
N=8
knightPos[ ] = {7, 7}
targetPos[ ] = {1, 5}
Output:
4
Explanation:
Knight takes 4 steps to reach from
(7, 7) to (1, 5):
(4, 5) -> (6, 5) -> (5, 3) -> (7, 2) -> (1, 5).

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.If it cannot reach the target position return -1.
*/

class Solution {
public:
    int delrow[8]={-1,1,2,-2,-1,1,-2,2};
    int delcol[8]={2,2,1,1,-2,-2,-1,-1};
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    if(KnightPos[0]==TargetPos[0] and KnightPos[1]==TargetPos[1]) return 0;
	    vector<vector<int>> vis(N+1,vector<int>(N+1,-1));
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    queue<pair<pair<int,int>,int>> q;
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    while(!q.empty()){
	        auto node=q.front();
	        q.pop();
	        int dist=node.second;
	        int i=node.first.first;
	        int j=node.first.second;
	        for(int k=0;k<8;k++){
	            int nrow=i+delrow[k];
	            int ncol=j+delcol[k];
	            if(nrow==TargetPos[0] and ncol==TargetPos[1]) return dist+1;
	            if(nrow>=0 and ncol>=0 and ncol<N and nrow<N and vis[nrow][ncol]==-1){
	                q.push({{nrow,ncol},dist+1});
	                vis[nrow][ncol]=1;
	            }
	        }
	    }
	return -1;
	}
};
