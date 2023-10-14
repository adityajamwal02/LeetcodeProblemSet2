/// Find Common Nodes in BST

class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    vector<int> result;
    unordered_map<int,int> mp;
    void inorder(Node *root){
        if(!root) return;
        if(root->left) inorder(root->left);
        if(mp[root->data]==0){
            mp[root->data]++;
        }else{
            result.push_back(root->data);
        }
        if(root->right) inorder(root->right);
    }
    vector <int> findCommon(Node *root1, Node *root2){
        inorder(root1);
        inorder(root2);
    return result;
    }
};
