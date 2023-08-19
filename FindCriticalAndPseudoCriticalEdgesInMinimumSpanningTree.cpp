/*
Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
Note that you can return the indices of the edges in any order.

Example 1:
Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:

Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:
Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
*/


class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            parent.resize(n,0);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int findParent(int node){
            if(node==parent[node]){
                return node;
            }
        return parent[node]=findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int uSet=findParent(u);
            int vSet=findParent(v);
            if(uSet==vSet) return;
            if(size[uSet]>size[vSet]){
                size[uSet]+=size[vSet];
                parent[vSet]=uSet;
            }else{
                size[vSet]+=size[uSet];
                parent[uSet]=vSet;
            }
        }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        DisjointSet dsu(n);
        auto adj=edges;
        int m=edges.size(), mstWeight=0;
        for(int i=0;i<m;i++){
            adj[i].push_back(i);
        }
        sort(adj.begin(),adj.end(),[&](auto &a, auto &b){
            return a[2]<b[2];
        });
        for(auto connection : adj){
            int u=connection[0], v=connection[1], wt=connection[2];
            if(dsu.findParent(u)!=dsu.findParent(v)){
                dsu.unionBySize(u,v);
                mstWeight+=wt;
            }
        }
        vector<int> criticalEdges, pseudoCriticalEdges;
        for(int i=0;i<m;i++){
            DisjointSet it1(n);
            int currMstWeight=0;
            for(int j=0;j<m;j++){
                if(i!=j){
                    int u=adj[j][0], v=adj[j][1], wt=adj[j][2];
                    if(it1.findParent(u)!=it1.findParent(v)){
                        it1.unionBySize(u,v);
                        currMstWeight+=wt;
                    }
                }
            }
            if(currMstWeight>mstWeight or currMstWeight<mstWeight){
                criticalEdges.push_back(adj[i][3]);
            }else{
                DisjointSet it2(n);
                it2.unionBySize(adj[i][0],adj[i][1]);
                int forcedMstWeight=adj[i][2];
                for(int j=0;j<m;j++){
                    if(i!=j){
                        int u=adj[j][0], v=adj[j][1], wt=adj[j][2];
                        if(it2.findParent(u)!=it2.findParent(v)){
                            it2.unionBySize(u,v);
                            forcedMstWeight+=wt;
                        }
                    }
                }
                if(forcedMstWeight==mstWeight){
                    pseudoCriticalEdges.push_back(adj[i][3]);
                }
            }
        }
    return {criticalEdges, pseudoCriticalEdges};
    }
};
