/*
Given a binary tree and a budget. Assume you are at the root of the tree(level 1), you need to maximise the count of leaf nodes you can visit in your budget if the cost of visiting a leaf node is equal to the level of that leaf node.

Example 1:
Input:
                  10
                /    \
               8      2
             /      /   \
            3      3     6
                    \
                     4
and budget = 8
Output: 2
Explanation:
Cost For visiting Leaf Node 3: 3
Cost For visiting Leaf Node 4: 4
Cost For visiting Leaf Node 6: 3
In budget 8 one can visit Max 2 Leaf Nodes.
Example 2:

Input:
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
and budget = 5
Output: 1
Explanation: We can only visit either node 4 or 5.
Your Task:

You don't need to read input or print anything. Your task is to complete the function getCount() which takes root node of the tree and a integer denoting the budget as input parameters and returns an integer denoting the count of visited leaf nodes of the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/


class Solution
{
public:
    int getCount(Node *root, int k)
    {
        queue<pair<Node*,int>> q;
        q.push({root,1});
        int counter=0;
        while(!q.empty() and k>0){
            auto node=q.front().first;
            auto level=q.front().second;
            q.pop();
            if(!node->left and !node->right){
                if(level>k){
                    return counter;
                }
                counter++;
                k-=level;
            }else{
                if(node->left) q.push({node->left,level+1});
                if(node->right) q.push({node->right,level+1});
            }
        }
    return counter;
    }
