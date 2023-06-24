/*
Given a Binary Tree of size N, you need to find all the possible paths from root node to all the leaf node's of the binary tree.

Example 1:
Input:
       1
    /     \
   2       3
Output: 1 2 #1 3 #
Explanation:
All possible paths:
1->2
1->3

Example 2:
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 10 20 40 #10 20 60 #10 30 #

Your Task:
Your task is to complete the function Paths() that takes the root node as an argument and return all the possible path. (All the path are printed '#' separated by the driver's code.)

Note: The return type
cpp: vector
java: ArrayList>
python: list of list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.
*/


void solve(Node *root, vector<int> &temp, vector<vector<int>> &result){
    if(!root) return;
    temp.push_back(root->data);
    solve(root->left,temp,result);
    solve(root->right,temp,result);
    if(!root->left and !root->right) result.push_back(temp);
temp.pop_back();
}
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> result;
    vector<int> temp;
    solve(root,temp,result);

return result;
}
