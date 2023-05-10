/*
Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
Note: You have to return list in sorted order.

Example 1:
Input:
          20
        /    \
      8       22
    /   \
   4    12
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.

Example 2:
Input:
         20
       /    \
      7      24
    /   \
   4     3
        /
       1
Target Node = 7
K = 2
Output: 1 24
Your Task:
You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(Height of tree
*/


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

    void findKDistanceNodes(Node* root, int k, vector<int>& result) {
        if (root == nullptr || k < 0)
            return;

        if (k == 0) {
            result.push_back(root->data);
            return;
        }

        findKDistanceNodes(root->left, k - 1, result);
        findKDistanceNodes(root->right, k - 1, result);
    }
    int findTargetNode(Node *root, int target, int k, vector<int> &result){
        if(!root) return -1;
        if(root->data == target){
            findKDistanceNodes(root,k,result);
            return 0;
        }
        int leftDistance = findTargetNode(root->left, target, k, result);
        if (leftDistance != -1) {
            if (leftDistance + 1 == k)
                result.push_back(root->data);
            else
                findKDistanceNodes(root->right, k - leftDistance - 2, result);
            return leftDistance + 1;
        }

        int rightDistance = findTargetNode(root->right, target, k, result);
        if (rightDistance != -1) {
            if (rightDistance + 1 == k)
                result.push_back(root->data);
            else
                findKDistanceNodes(root->left, k - rightDistance - 2, result);
            return rightDistance + 1;
        }
    return -1;
    }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> result;
        if(!root) return result;
        findTargetNode(root,target,k,result);
        sort(result.begin(), result.end());
    return result;
    }
};
