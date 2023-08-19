/*
Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.
A grandparent of a node is the parent of its parent if it exists.

Example 1:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

Example 2:
Input: root = [1]
Output: 0
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
    int result=0;
    int grandParent(TreeNode* root){
        int sum=0;
        if(root->left){
            if(root->left->left){
                sum+=root->left->left->val;
            }
            if(root->left->right){
                sum+=root->left->right->val;
            }
        }
        if(root->right){
            if(root->right->left){
                sum+=root->right->left->val;
            }
            if(root->right->right){
                sum+=root->right->right->val;
            }
        }
    return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        if(root->val%2==0){
            result+=grandParent(root);
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
    return result;
    }
};
