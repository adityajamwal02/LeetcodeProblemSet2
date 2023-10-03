/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
Each minute, a node becomes infected if:
The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Example 1:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
*/

class Solution {
public:
    int findMaxTime(map<TreeNode*,TreeNode*> &mp, TreeNode *target){
        queue<TreeNode*> q;
        q.push(target);
        int maxTime=0;
        map<TreeNode*,int> vis;
        vis[target]=1;
        while(!q.empty()){
            int sz=q.size(), flag=0;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                if(curr->left and !vis[curr->left]){
                    flag=1;
                    vis[curr->left]=1;
                    q.push(curr->left);
                }
                if(curr->right and !vis[curr->right]){
                    flag=1;
                    vis[curr->right]=1;
                    q.push(curr->right);
                }
                if(mp[curr] and !vis[mp[curr]]){
                    flag=1;
                    vis[mp[curr]]=1;
                    q.push(mp[curr]);
                }
            }
        if(flag) maxTime++;
        }
    return maxTime;
    }

    TreeNode *helper(TreeNode *root, map<TreeNode*,TreeNode*> &mp, int start){
        TreeNode *result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr->val==start) result=curr;
            if(curr->left){
                mp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right]=curr;
                q.push(curr->right);
            }
        }
    return result;
    }

    int amountOfTime(TreeNode* root, int start){
        map<TreeNode*,TreeNode*> mp;
        TreeNode* target=helper(root,mp,start);
        int maxTime=findMaxTime(mp,target);
    return maxTime;
    }
};
