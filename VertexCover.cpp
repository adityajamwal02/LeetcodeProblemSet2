/*
Given an undirected graph G return, the minimum number of vertexes that are needed so that every vertex is adjacent to the selected one.In short return the size of the vertex cover of the graph.

Example 1:

Input:
N=5
M=6
edges[][]={{1,2}
{4, 1},
{2, 4},
{3, 4},
{5, 2},
{1, 3}}
Output:
3
Explanation:
Just pick 2,3,4.
Example 2:

Input:
N=2
M=1
edges[][]={{1,2}}
Output:
1
Explanation:
Pick either 1 or 2.


Your Task:
You don't need to read input or print anything. Your task is to complete the function vertexCover() which takes the edge list and number of nodes of the graph as input parameters and returns the size of the vertex cover.


*/

/// Bitset + Graph + Binary Search

//User function Template for C++

class Solution{
    public:
        vector<vector<int>> adj;
        bool isPossible(int n, int m, int mid){
            int initial_set=(1<<mid)-1;
            int maxLimit=(1<<n);
            while(initial_set<maxLimit){
                bool vis[n+1][n+1]={0};
                int edgesCovered=0;
                for(int j=1,u=1;j<maxLimit;j=j<<1,u++){
                    if(initial_set&j){
                        for(int v=1;v<=n;v++){
                            if(adj[u][v] and !vis[u][v]){
                                edgesCovered++;
                                vis[u][v]=1;
                                vis[v][u]=1;
                            }
                        }
                    }
                }
                if(edgesCovered==m) return true;
            int rightMostSetBit=(initial_set)&(-initial_set);
            int val=initial_set+(rightMostSetBit);
            initial_set=(((val^initial_set)>>2)/rightMostSetBit)|val;
            }
        return false;
        }

        int vertexCover(int n, vector<pair<int, int>> &edges) {
            int m=edges.size();
            adj.resize(n+1,vector<int>(n+1));
            for(auto edge : edges){
                adj[edge.first][edge.second]=1;
                adj[edge.second][edge.first]=1;
            }
            int low=1, high=n;
            while(low<high){
                int mid=low+(high-low)/2;
                if(isPossible(n,m,mid)){
                    high=mid;
                }else{
                    low=mid+1;
                }
            }
        return low;
        }
};
