/*
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.
Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

Example 1 :

Input :
               1
             /   \
           2       3
         /   \       \
        4     5       2
                     /  \
                    4    5
Output : 1
Explanation :
    2
  /   \
 4     5
is the duplicate sub-tree.
Example 2 :

Input :
               1
             /   \
           2       3
Output: 0
Explanation: There is no duplicate sub-tree
in the given binary tree.
Your Task:
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only argument and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
*/

class Solution {
  public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string,int> mp;
    int counter=0;

    string solve(Node *root){
        if(!root) return "#";
        string s=to_string(root->data)+","+solve(root->left)+","+solve(root->right);
        if(root->left or root->right){
            mp[s]++;
        }
    return s;
    }

    int dupSub(Node *root){
        solve(root);
        for(auto it : mp){
            if(it.second>1) counter=1;
        }
    return counter;
    }
};
