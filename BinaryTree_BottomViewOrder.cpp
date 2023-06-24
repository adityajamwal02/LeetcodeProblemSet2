/*
Problem Statement: Given a binary tree, print the bottom view from left to right.
A node is included in the bottom view if it can be seen when we look at the tree from the bottom.
*/


/// Bottom view (Binary Tree)

//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> result;
        if(!root) return result;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node *temp=q.front().first;
                int level=q.front().second;
                q.pop();
                mp[level]=temp->data;
                if(temp->left) q.push({temp->left,level-1});
                if(temp->right) q.push({temp->right,level+1});
            }
        }
        for(auto it : mp){
            result.push_back(it.second);
        }
    return result;
    }
};
