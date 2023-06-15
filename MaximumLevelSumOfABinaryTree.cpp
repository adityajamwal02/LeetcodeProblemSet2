/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Example 1:
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
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
    int maxLevelSum(TreeNode* root) {
        vector<pair<long long,int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(!q.empty()){
            int sz=q.size();
            long long currSum=0;
            for(int i=0;i<sz;i++){
                auto temp=q.front();
                q.pop();
                currSum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        result.push_back({currSum,level});
        level++;
        }
    sort(result.rbegin(),result.rend(), [](pair<long long,int> &a, pair<long long,int> &b){
        if(a.first==b.first) return a>b;
    return a<b;
    });
    return result[0].second;
    }
};
