/*
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]
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
    void solve(TreeNode* root, string temp, vector<string> &result){
        if(!root) return;
        if(!root->left and !root->right){
            temp+=to_string(root->val);
            result.push_back(temp);
            return;
        }
        temp+=to_string(root->val);
        temp.push_back('-');
        temp.push_back('>');
        solve(root->left,temp,result);
        solve(root->right,temp,result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string temp="";
        solve(root,temp,result);
    return result;
    }
};
