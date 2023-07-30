/*
Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

Example 1:
Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3
Explanation:
Inorder traversal : 1 2 3
Hence, inorder successor of 2 is 3.

Example 2:
Input:
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
K(data of x) = 8
Output: 10
Explanation:
Inorder traversal: 4 8 10 12 14 20 22
Hence, successor of 8 is 10.

Your Task:
You don't need to read input or print anything. Your task is to complete the function inOrderSuccessor(). This function takes the root node and the reference node as argument and returns the node that is inOrder successor of the reference node. If there is no successor, return null value.


Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void helper(Node* root, vector<Node*> &result){
        if(!root) return;
        helper(root->left,result);
        result.push_back(root);
        helper(root->right,result);
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        vector<Node*> result;
        helper(root,result);
        int n=result.size();
        for(int i=0;i<n;i++){
            if(result[i]==x and i!=n-1){
                return result[i+1];
            }
        }
    return NULL;
    }
};

/// Optimal Solution

 Node * inOrderSuccessor(Node *root, Node *x)
    {
       Node *temp=root;
       Node *ans=NULL;
       while(temp!=NULL)
       {
           if(temp->data<=x->data)
           temp=temp->right;
           else
           {
               ans=temp;
               temp=temp->left;
           }
       }
       return ans;
    }
