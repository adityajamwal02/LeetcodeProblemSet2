/*
Given a directed graph and two vertices ‘u’ and ‘v’ in it. Find the number of possible walks from ‘u’ to ‘v’ with exactly k edges on the walk modulo 109+7.

Note : There can be a cycle in the graph and an edge can be travelled multiple times.

Example 1:
Input 1: graph = {{0,1,1,1},{0,0,0,1},
{0,0,0,1}, {0,0,0,0}}, u = 0, v = 3, k = 2
Output: 2
Explanation: Let source ‘u’ be vertex 0,
destination ‘v’ be 3 and k be 2. The output
should be 2 as there are two walk from 0 to
3 with exactly 2 edges. The walks are {0, 2, 3}
and {0, 1, 3}.

Your Task:
You don't need to read or print anything. Your task is to complete the function MinimumWalk() which takes graph, u, v and k as input parameter and returns total possible paths from u to v using exactly k edges modulo 109+7.
Note: In graph, if graph[i][j] = 1, it means there is an directed edge from vertex i to j.

Expected Time Complexity: O(n3)
Expected Space Complexity: O(n3)
*/


/// DP Solution

//User function template for C++

class Solution {
  public:
    int mod=1e9+7;

    int dfs(unordered_map<int, vector<int>> &adj, int u, int v, int k, int temp, vector<vector<vector<int>>> &dp){
        if(temp>k) return 0;
        if(u==v and temp==k) return 1;
        if(dp[u][temp][k]!=-1) return dp[u][temp][k];
        int count=0;
        for(auto it : adj[u]){
            count=(count+dfs(adj,it,v,k,temp+1,dp))%mod;
        }
    return dp[u][temp][k]=count;
    }

	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    unordered_map<int, vector<int>> adj;
	    int n=graph.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<graph[0].size();j++){
	            if(graph[i][j]==1){
	                adj[i].push_back(j);
	            }
	        }
	    }
	    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1,vector<int>(k+1,-1)));
	return dfs(adj,u,v,k,0,dp);
	}

};
