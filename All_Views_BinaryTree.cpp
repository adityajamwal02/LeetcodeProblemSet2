/// All Views Binary Tree

/// Bottom View (Idea: Consider axis about root, left side -> -ve and right side -> +ve , use map to store the latest occurrence in that level)

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> result;
        if(!root) return result;
        map<int,int> mp;                /// Col, val
        queue<pair<Node*,int>> q;
        q.push({root,0});               /// Queue {Node and Level (-ve , 0, +ve}
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

/// Top View (Idea: Consider axis about root, left side -> -ve and right side -> +ve , use map to store the first occurrence in that level by checking its already presence or not)

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if(!root) return result;
        map<int,int> mp;            // col,val
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node *temp=q.front().first;
                int level=q.front().second;
                q.pop();
                if(mp.find(level)==mp.end()) mp[level]=temp->data;
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


/// Vertical Order Traversal (View) // Idea: Maintaining Map (ordered), keep pushing into the level and return into vector afterwards

vector<int> verticalOrder(Node *root)
    {
        vector<int> result;
        if(!root) return result;
        map<int,vector<int>> mp;     // col, vector
        queue<pair<Node*,int>> q;   // Node, level
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node *temp=q.front().first;
                int level=q.front().second;
                q.pop();
                mp[level].push_back(temp->data);
                if(temp->left) q.push({temp->left,level-1});
                if(temp->right) q.push({temp->right,level+1});
            }
        }
        for(auto it : mp){
            vector<int> temp=it.second;
            for(auto ele : temp){
                result.push_back(ele);
            }
        }
    return result;
    }

    /// Multiset and map based solution (Optimal)

    class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }
             if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
        ans.push_back(col);
        }
    return ans;
    }
};


/// Left Side View (Idea: recursion, start from root, go to left->left , if not then only go left->right,

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

/// Left Side View (Queue)

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


/// Right Side View (Idea: recursion, start from root, go to right->right , if not then only go right->left,

class Solution {
public:
    void helper(TreeNode *root, int level, vector<int> &result){
        if(!root) return;
        if(result.size()==level){
            result.push_back(root->val);
        }
        helper(root->right,level+1,result);
        helper(root->left,level+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        helper(root,0,result);
    return result;
    }
};

/// Right Side View (Queue)

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
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                if(i==n-1)
                    res.push_back(node->val);
            }
        }
    return res;
    }
};

/// Boundary View : (Idea : Combination of left side + leaf nodes + right side view)

bool isLeaf(Node *root){
    if(!root->left and !root->right) return true;

return false;
}

void addLeftBoundary(Node *root, vector<int> &result){
    Node *curr=root->left;
    while(curr){
        if(!isLeaf(curr)) result.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addLeaves(Node *root, vector<int> &result){
    if(isLeaf(root)){
        result.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left,result);
    if(root->right) addLeaves(root->right,result);
}

void addRightBoundary(Node *root, vector<int> &result){
    Node *curr=root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        result.push_back(temp[i]);
    }
}

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        vector<int> result;
        if(!root) return result;
        if(!isLeaf(root)) result.push_back(root->data);

        addLeftBoundary(root,result);

        addLeaves(root,result);

        addRightBoundary(root,result);

    return result;
    }
};

