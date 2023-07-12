/*
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
Explanation:
unnamed
Diagonal Traversal of binary tree :
 8 10 14 3 6 7 13 1 4
Your Task:
You don't need to read input or print anything. The task is to complete the function diagonal() that takes the root node as input argumets and returns the diagonal traversal of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Here N is number of nodes.
*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
    vector<int> result;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            while(node){
                result.push_back(node->data);
                if(node->left) q.push(node->left);
                node=node->right;
            }
        }
    }
    return result;
}

