/*
Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Example 1:
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:
Input: n = 3
Output: [[0,0,0]]
*/


/// Recursive

class Solution {
public:
    vector<TreeNode*> helper(int n){
        if(n==1){
            vector<TreeNode*> temp ;
            temp.push_back(new TreeNode(0));
            return temp;
        }
        vector<TreeNode*> ans ;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n-i-1);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};

/// Memoized

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
    vector<TreeNode*> helper(int n, vector<TreeNode*> dp[]){
        if(n==1) return {new TreeNode(0)};
        if(dp[n].size()) return dp[n];
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftTree=helper(i,dp);
            vector<TreeNode*> rightTree=helper(n-i-1,dp);
            int leftSize=leftTree.size();
            int rightSize=rightTree.size();
            for(auto l : leftTree){
                for(auto r : rightTree){
                    TreeNode *root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    dp[n].push_back(root);
                }
            }
        }
    return dp[n];
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        vector<TreeNode*> dp[20];
    return helper(n,dp);
    }
};
