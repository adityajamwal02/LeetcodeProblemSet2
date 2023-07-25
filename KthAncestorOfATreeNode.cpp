/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
The kth ancestor of a tree node is the kth node in the path from that node to the root node.
Implement the TreeAncestor class:
TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.

Example 1:
Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor
*/


/// Dp On Trees

class TreeAncestor {
public:
    // Using concept of Binary Lifting (Trees)

    int height;                              // To store height of the tree
    vector<vector<int>> sparseTable;         // Consider this dp part
    // Since we are using this for preprocessing for queries further

    TreeAncestor(int n, vector<int>& parent) {
        height=(int)ceil(log2(n));
        sparseTable.resize(n,vector<int>(height+1,-1));
        for(int i=0;i<n;i++){
            sparseTable[i][0]=parent[i];
        }
        for(int i=1;i<height;i++){
            for(int j=0;j<n;j++){
                if(sparseTable[j][i-1]>=0){
                    sparseTable[j][i]=sparseTable[sparseTable[j][i-1]][i-1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        // Doing bitwise operation to check the set bits
        for(int i=0;i<=height;i++){
            if(k&(1<<i)){
                node=sparseTable[node][i];
                if(node==-1) return -1;
            }
        }
    return node;
    }
};
