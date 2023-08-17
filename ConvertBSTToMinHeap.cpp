/// BST To MinHeap

#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure:

	class BinaryTreeNode {

	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/

void inorder(BinaryTreeNode *root, vector<int> &result){
	if(!root) return;
	inorder(root->left,result);
	result.push_back(root->data);
	inorder(root->right,result);
}

void makeMinHeap(BinaryTreeNode *root, vector<int> result, int &index){
	if(!root) return;
	root->data=result[index++];
	makeMinHeap(root->left, result, index);
	makeMinHeap(root->right, result, index);
}


BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> result;
	int index=0;
	inorder(root,result);
	makeMinHeap(root,result,index);
return root;
}
