
class Solution{

public:
    vector<int> leftSideView(TreeNode* root){
        vector<int> ans;
        helper(root, 0, ans);

        return ans;
    }

    void helper(TreeNode* root,int level,vector<int> &ans){
        if(root==NULL)
            return ;
        if(ans.size()==level)
            ans.push_back(root->val);

        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
    }
};


/// left side view using level order

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode * node = q.front();
                q.pop();
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
                if(i==n-1)
                    res.push_back(node->val);
            }
        }
    return res;
    }
};
