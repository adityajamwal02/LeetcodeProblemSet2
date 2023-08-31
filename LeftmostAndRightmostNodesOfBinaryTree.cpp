/*
Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

Example 1:
Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7
Output: 1 2 3 4 7
Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7

Example 2:
Input:

        10
      /    \
     20     30
    / \
   40  60
Output: 10 20 30 40 60
Your Task:
You dont need to read input. Complete the function printCorner() which takes root node as input parameter and prints the corner nodes separated by spaces. The left corner should be printed before the right for each level starting from level 0.
Note: Don't print a new line after printing all the corner nodes.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(number of nodes in a level)
*/

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        int nodeCount=0;
        while(nodeCount<sz){
            Node *temp=q.front();
            q.pop();
            if(nodeCount==0 or nodeCount==sz-1){
                cout<<temp->data<<" ";
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        nodeCount++;
        }
    }

}
