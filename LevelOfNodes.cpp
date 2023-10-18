/*
Given an integer X and an undirected acyclic graph with V nodes, labeled from 0 to V-1, and E edges, find the level of node labeled as X.
Level is the minimum number of edges you must travel from the node 0 to some target.
If there doesn't exists such a node that is labeled as X, return -1.

Example 1:
Input:
X = 4
Output:
2
Explanation:
We can clearly see that Node 4 lies at Level 2.

Example 2:
Input:
X = 1
Output:
1
Explanation:
Node 1 lies at level 1, immediate after Node 0.
Your task:
You dont need to read input or print anything. Your task is to complete the function nodeLevel() which takes two integers V and X denoting the number of vertices and the node, and another adjacency list adj as input parameters and returns the level of Node X. If node X isn't present it returns -1.
*/

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X){
	    queue<pair<int,int>> q;
	    vector<int> vis(V,0);
	    q.push({0,0});
	    vis[0]=1;
	    while(!q.empty()){
	        int val=q.front().first;
	        int lev=q.front().second;
	        q.pop();
	        for(auto it : adj[val]){
	            if(!vis[it]){
	                vis[it]=1;
	                q.push({it,lev+1});
	            }
	            if(it==X) return lev+1;
	        }
	    }
	return -1;
	}
};
