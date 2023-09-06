/*
Given a Directed Graph, find a Mother Vertex in the Graph (if present).
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

Example 1:
Input:
Output: 0
Explanation: According to the given edges, all
nodes can be reaced from nodes from 0, 1 and 2.
But, since 0 is minimum among 0,1 and 2, so 0
is the output.

Example 2:
Input:
Output: -1
Explanation: According to the given edges,
no vertices are there from where we can
reach all vertices. So, output is -1.
Your Task:
You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices and adjacency list as imput parameter and returns the verticex from through which we can traverse all other vertices of the graph. If there is more than one possible nodes then returns the node with minimum value.If not possible returns -1.
*/

class Solution
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node,vector<int> adj[], set<int> &st, vector<int> &vis){
        vis[node]=1;
        st.insert(node);
        for(auto it : adj[node]){
            if(st.find(it)==st.end()){
                dfs(it,adj,st,vis);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        set<int> st;
	        if(!vis[i]){
	            dfs(i,adj,st,vis);
	        }
	        if(st.size()==V) return i;
	    }
	return -1;
	}
};
