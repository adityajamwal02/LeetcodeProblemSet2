/// Sum of nodes at Kth Level

#include <bits/stdc++.h>
/**********************************************************************

Following is the Binary Tree node structure already written:

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

**********************************************************************/

int sumAtKthLevel(BinaryTreeNode<int>* root, int k)
{
    if(!root) return 0;
    if(k==1) return root->data;
    int level=0, result=0, flag=0;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,1});
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            level=it.second;
            if(level==k){
                // flag=1;
                result+=(it.first->data);
            }else{
                if(it.first->left)
                    q.push({it.first->left, level + 1});
                if(it.first->right)
                    q.push({it.first->right, level + 1});
            }
        }
        // if(flag==1) break;
    }
    return result;
}
