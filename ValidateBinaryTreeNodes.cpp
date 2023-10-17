/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
Note that the nodes have no values and that we only use the node numbers in this problem

Example 1:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

Example 2:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false

Example 3:
Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
*/

class disjointSet{
public:
    vector<int> parent, size;
    disjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int node){
        if(node==parent[node]) return node;
    return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int parU=findParent(u);
        int parV=findParent(v);
        if(parU==parV) return;
        if(size[parU]<size[parV]){
            parent[parU]=parV;
            size[parV]+=parU;
        }else{
            parent[parV]=parU;
            size[parU]+=parV;
        }
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){
        disjointSet dsu(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            int x=leftChild[i], y=rightChild[i];
            if(x!=-1 and vis[x]==0){
                vis[x]=1;
                if(dsu.findParent(i)==dsu.findParent(x)) return false;
                dsu.unionBySize(i,x);
            }else if(x!=-1 and vis[x]==1) return false;
            if(y!=-1 and vis[y]==0){
                vis[y]=1;
                if(dsu.findParent(i)==dsu.findParent(y)) return false;
                dsu.unionBySize(i,y);
            }else if(y!=-1 and vis[y]==1) return false;
        }
        int counter=1;
        for(int i=1;i<n;i++){
            if(dsu.findParent(i)!=dsu.findParent(0)) counter++;
        }
    return counter==1;
    }
};
