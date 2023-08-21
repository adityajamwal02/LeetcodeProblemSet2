/// N-ary Tree to Binary Tree

#include <bits/stdc++.h>
/************************************************************
    Binary tree node class for reference:

    template <typename T>
    class BTreeNode {
        public:
        T val;
        BTreeNode < T > * left;
        BTreeNode < T > * right;

        BTreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

    Nary tree node class for reference:

    class NTreeNode {
        public:
        T val;
        vector < NTreeNode < T > * > child;

        NTreeNode(T val) {
            this -> val = val;
        }
    };

************************************************************/

BTreeNode < int > * encode(NTreeNode < int > * root) {
    if(!root) return NULL;
    BTreeNode<int> *binaryRoot=new BTreeNode<int>(root->val);
    if(!root->child.empty()){
        binaryRoot->left=encode(root->child[0]);
    }
    BTreeNode<int> *currBinary=binaryRoot->left;
    for(int i=1;i<root->child.size();i++){
        currBinary->right=encode(root->child[i]);
        currBinary=currBinary->right;
    }
return binaryRoot;
}

NTreeNode<int> *decode(BTreeNode<int> *root) {
    if(!root) return NULL;
    NTreeNode<int> *nAryRoot=new NTreeNode<int>(root->val);
    BTreeNode<int> *currBinary=root->left;
    while(currBinary){
        nAryRoot->child.push_back(decode(currBinary));
        currBinary=currBinary->right;
    }
    return nAryRoot;
}
