/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
If the tree has more than one mode, return them in any order.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [1,null,2,2]
Output: [2]

Example 2:
Input: root = [0]
Output: [0]
*/

/// O(n) space

    void helper(TreeNode* root, unordered_map<int,int> &mp){
        if(!root) return;
        mp[root->val]++;
        helper(root->left,mp);
        helper(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        // int maxFreq=0, currFreq=0, prev=INT_MIN;
        // inorder(root,currFreq,maxFreq,prev,result);
        unordered_map<int,int> mp;
        int maxFreq=0;
        vector<int> result;
        helper(root,mp);
        for(auto it : mp){
            maxFreq=max(maxFreq,it.second);
        }
        for(auto it : mp){
            if(it.second==maxFreq){
                result.push_back(it.first);
            }
        }
    return result;
    }
};

/// O(1) space
