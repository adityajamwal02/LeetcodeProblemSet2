/*
Reverse Delete algorithm is closely related to Kruskal’s algorithm. In Reverse Delete algorithm, we sort all edges in decreasing order of their weights. After sorting, we one by one pick edges in decreasing order. We include current picked edge if excluding current edge causes disconnection in current graph. The main idea is delete edge if its deletion does not lead to disconnection of graph. Your task is to print the value of total weight of Minimum Spanning Tree formed.

Example 1:
Input:
V = 4, E = 5
Arr[] = {0, 1, 10, 0, 2, 6, 0, 3, 5, 1, 3, 15, 2, 3, 4}
Output:
19
Explanation:
The weight of the Minimum Spanning
Tree formed is 19.

Example 2:
Input:
V = 4, E = 3
Arr[] = {0, 1, 98, 1, 3, 69, 0, 3, 25}
Output:
192
Explanation:
The weight of the Minimum Spanning
Tree formed is 192.

Your Task:
You don't need to read input or print anything. Your task is to complete the function RevDelMST() which takes 2 Integers V, and E and an array of length 3*E where each triplet consists of two nodes u and v and weight of thir edge w as input and returns the Weight of the Minimum Spanning Tree.

Expected Time Complexity: O(V*E)
Expected Auxiliary Space: O(E)
*/


/// DSU


class DSU{

private:
    vector<int> parent, rank;
    int size;

public:
    DSU(int size){
        this->size=size;
        for(int i=0;i<size;i++){
            parent.push_back(i);
            rank.push_back(1);
        }
    }
    int findParent(int a){
        if(a==parent[a]) return a;
        else return parent[a]=findParent(parent[a]);
    }
    void unionByRank(int a, int b){
        assert(a<size);
        assert(b<size);
        int parent_A=findParent(a);
        int parent_B=findParent(b);
        if(parent_A == parent_B) return;
        if(rank[parent_A] > rank[parent_B]){
            parent[parent_B]=parent_A;
            rank[parent_A]+=rank[parent_B];
        }else{
            parent[parent_A]=parent_B;
            rank[parent_B]+=rank[parent_B];
        }
    }
    bool isConnected(int a, int b){
        assert(a<size);
        assert(b<size);
        if(findParent(a)==findParent(b)) return true;
        else return false;
    }
};

class Solution {
  public:
    int RevDelMST(int Arr[], int V, int E) {
        vector<vector<int>> edges;
        vector<int> degree(V,0);
        for(int i=0;i<(3*E)-2;i+=3){
            int u=Arr[i];
            int v=Arr[i+1];
            int w=Arr[i+2];
            edges.push_back({u,v,w});
        }
        sort(edges.begin(),edges.end(), [] (vector<int> &a, vector<int> &b) { return a[2]<b[2]; });
        int weight=0;
        DSU ds(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(!ds.isConnected(u,v)){
                weight+=w;
                ds.unionByRank(u,v);
            }
        }
    return weight;
    }
};
