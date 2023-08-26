/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
Input: root = [2,1,3]
Output: [2,1,3]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<TreeNode*> &result){
        if(!root) return;
        inorderTraversal(root->left,result);
        result.push_back(root);
        inorderTraversal(root->right,result);
    }

    TreeNode* buildTree(int low, int high, vector<TreeNode*> &inorder){
        if(low>high) return NULL;
        int mid=(low+high)/2;
        TreeNode *root=inorder[mid];
        root->left=buildTree(low,mid-1,inorder);
        root->right=buildTree(mid+1,high,inorder);
    return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<TreeNode*> inorder;
        inorderTraversal(root,inorder);
        int n=inorder.size();
        root=buildTree(0,n-1,inorder);
    return root;
    }
};
