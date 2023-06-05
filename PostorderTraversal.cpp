/*
Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:
5 10 39 1

        1
     /     \
   10     39
  /
5

Example 1:
Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19

Example 2:
Input:
          11
         /
       15
      /
     7
Output: 7 15 11

Your Task:
You don't need to read input or print anything. Your task is to complete the function postOrder() that takes root node as input and returns an array containing the postorder traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/


//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.

void helper(Node* root, vector<int> &result){
    if(!root) return;
    helper(root->left,result);
    helper(root->right,result);
    result.push_back(root->data);
}

vector <int> postOrder(Node* root)
{
    vector<int> result;
    helper(root,result);
return result;
}
