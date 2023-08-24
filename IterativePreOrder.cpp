
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            result.push_back(it->val);
            if(it->right) st.push(it->right);
            if(it->left) st.push(it->left);
        }
    return result;
    }
};
