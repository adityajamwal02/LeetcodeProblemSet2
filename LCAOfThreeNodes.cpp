/// LCA Of Three Nodes

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
	if(!root or root->data==node1 or root->data==node2 or root->data==node3) return root;
	BinaryTreeNode<int> *left=lcaOfThreeNodes(root->left,node1,node2,node3);
	BinaryTreeNode<int> *right=lcaOfThreeNodes(root->right,node1,node2,node3);
	if(!left) return right;
	if(!right) return left;
	else return root;
}
