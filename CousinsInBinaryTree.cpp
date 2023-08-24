/// Cousins in Binary Tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            bool flagx=false, flagy=false;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                if(it->val==x) flagx=true;
                if(it->val==y) flagy=true;
                if(it->left and it->right){
                    if((it->left->val==x and it->right->val==y) or (it->left->val==y and it->right->val==x))
                        return false;
                }
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(flagx and flagy) return true;
        }
    return false;        
    }
};
