/*
The maximum width of a binary tree is the maximum of all the level widths. Width for a level is defined as the maximum number of nodes
between the leftmost and rightmost node of the level(including the end nodes and the null nodes between the end nodes).
*/


/// Level Order Solution

int widthOfBinaryTree(node * root) {
  if (!root)
    return 0;
  int ans = 0;
  queue < pair < node * , int >> q;
  q.push({root,0});
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      node * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({
          temp -> left,
          cur_id * 2 + 1
        });
      if (temp -> right)
        q.push({
          temp -> right,
          cur_id * 2 + 2
        });
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}

/// DFS based : Recursive Solution

/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    unordered_map<int,int> mp;

    void helper(Node *root, int level){
        if(!root) return;
        mp[level]++;
        helper(root->left,level+1);
        helper(root->right,level+1);
    }

    int getMaxWidth(Node* root) {
        if(!root) return NULL;
        if(!root->left and !root->right) return 1;
        int result=0;
        helper(root,0);
        for(auto it : mp){
            result=max(result,it.second);
        }
    return result;
    }
};
