/*
Given the root of a binary tree, return the sum of values of its deepest leaves.

Example 1:
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
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

 /// Idea: BFS each level (sum store in map)

class Solution {
public:
    int deepestLeavesSum(TreeNode* root){
        map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            level+=1;
            int sz=q.size(), currSum=0;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                currSum+=node->val;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        mp[level]=currSum;
        }
    return mp[mp.size()];
    }
};
