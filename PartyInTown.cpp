/*
Geek town has N Houses numbered from 1 to N. They are connected with each other via N-1 bidirectional roads. Given an adjacency list adj to represent the connections. To host the optimal party, you need to identify the house from which the distance to the farthest house is minimum. Find this distance.

Example 1:
Input:
N = 4
adj = {{2},{1,3,4},{2},{2}}
Output: 1
Explaination:

Party should take place at house number 2.
Maximum distance from house number 2 is 1.

Example 2:
Input:
N = 4
adj = {{2},{1,3},{2,4},{3}}
Output:
2
Explanation:
Party should take place at house number 2 or 3.
So, the minimum distance between the farthest
house and the party house is 2.

Your Task:
You do not need to read input or print anything. Your task is to complete the function partyHouse() which takes N and adj as input parameters and returns the minimum possible distance to the farthest house from the house where the party is happening.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)
*/


// User function Template for C++

class Solution{
public:
    int dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        int dis=0;
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dis=max(dis,1+dfs(it,vis,adj));
            }
        }
    return dis;
    }
    int partyHouse(int N, vector<vector<int>> &adj){
        int result= INT_MAX;
        for(int i=1;i<=N;i++){
            vector<int> vis(N+1,0);
            vis[i]=1;
            result=min(result,dfs(i,vis,adj));
        }
    return result;
    }
};
