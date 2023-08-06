/*
Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.

Example 1:
Input:
N = 2
arr = {2,1}
Output: {1}
Explaination: 1 is the only leaf node.

Example 2:
Input:
N = 3
Arr = {3, 2, 4}
Output: {2, 4}
Explaination: 2, 4 are the leaf nodes.

Your Task:
You don't need to read input or print anything. Your task is to complete the function leafNodes() which takes the array arr[] and its size N as input parameters and returns the leaf nodes of the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

class Solution {
  public:
    unordered_map<int,int> mp;
    void helper(int arr[], int preStart, int preEnd, vector<int> &inorder, int inorderStart, int inorderEnd, vector<int> &result){
        if(preStart>preEnd or inorderStart>inorderEnd) return;
        if(preStart==preEnd) result.push_back(arr[preStart]);
        int inRoot=mp[arr[preStart]];
        int numsLeft=inRoot-inorderStart;
        helper(arr,preStart+1,preStart+numsLeft,inorder,inorderStart,inRoot-1,result);
        helper(arr,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inorderEnd,result);
    }

    vector<int> leafNodes(int arr[],int N) {
        mp.clear();
        vector<int> result, inorder(N);
        for(int i=0;i<N;i++){
            inorder[i]=arr[i];
        }
        sort(inorder.begin(), inorder.end());
        for(int i=0;i<N;i++){
            mp[inorder[i]]=i;
        }
        helper(arr,0,N-1,inorder,0,N-1,result);
    return result;
    }
};
