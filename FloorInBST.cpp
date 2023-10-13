/// Floor BST

class Solution{

public:
    void helper(Node *root, int x, int &res){
        if(!root) return;
        if(root->data <= x) res=max(res,root->data);
        helper(root->left,x,res);
        helper(root->right,x,res);
    }
    int floor(Node* root, int x){
        int result=-1;
        helper(root,x,result);
    return result;
    }
};
