/*
Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.

Example 1:
Input:
Output:
0 1 2,3,4,
Explanation:
We can clearly see that there are 3 Strongly
Connected Components in the Graph as mentioned
in the Output.

Example 2:
Input:
Output:
0 1 2,
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC as shown.

Your Task:
You don't need to read input or print anything. Your task is to complete the function tarjans() which takes the number of vertices V and adjacency list of the graph as input parameters and returns a list of list of integers denoting the members of strongly connected components in the given graph.
Note: A single strongly connected component must be represented in the form of a list if integers sorted in the ascending order. The resulting list should consist of a list of all SCCs which must be sorted in a way such that a lexicographically smaller list of integers appears first.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).
*/

class Solution
{
	public:

	void dfs(int s,stack<int> &st,vector<int> &disc,vector<int> &low,vector<bool>&ps,vector<vector<int>> &result,vector<int> adj[],int &timer){
     disc[s]=low[s]=timer++;
     st.push(s);
     ps[s]=true;
     for(auto nbr:adj[s])
     {
         if(disc[nbr]==-1){
             dfs(nbr,st,disc,low,ps,result,adj,timer);
             low[s]=min(low[nbr],low[s]);
         }
         else if(ps[nbr]){
             low[s]=min(low[s],disc[nbr]);
         }
     }
     if(low[s]==disc[s]){
         vector<int> ans;
         while(st.top()!=s){
             ans.push_back(st.top());
             ps[st.top()]=false;
             st.pop();
         }
         ans.push_back(st.top());
         ps[st.top()]=false;
         st.pop();
         sort(ans.begin(),ans.end());
         result.push_back(ans);
     }
 }

    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {

        int timer=0;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        vector<bool> ps(V,false);
        stack<int> st;
        vector<vector<int>> result;
        for(int i=0;i<V;i++){
            if(disc[i]==-1){
                dfs(i,st,disc,low,ps,result,adj,timer);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
