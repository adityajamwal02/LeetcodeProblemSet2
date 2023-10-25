/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]
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
    vector<int> largestValues(TreeNode* root){
        vector<int> result;
        if(!root) return result;
        int maxi=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size(), maxi=INT_MIN;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                if(maxi<it->val){
                    maxi=it->val;
                }
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        result.push_back(maxi);
        }
    return result;
    }
};
