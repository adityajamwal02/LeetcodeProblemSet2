/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 Example 1:

Input:
      1
    /   \
   2     3
Output:
1 2 3
Explanation:
The converted BST will be
      2
    /   \
   1     3

Example 2:

Input:
          1
       /    \
     2       3
   /
 4
Output:
1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
*/

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int> arr;
    int i=0;

    void buildBST(Node *root){
        if(!root) return;
        buildBST(root->left);
        root->data=arr[i];
        i++;
        buildBST(root->right);
    }

    void inorder(Node *root){
        if(!root) return;
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }

    Node *binaryTreeToBST (Node *root)
    {
        inorder(root);
        sort(arr.begin(),arr.end());
        buildBST(root);
    return root;
    }
};
