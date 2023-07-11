
/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
	public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void findKDistanceNodes(BinaryTreeNode<int>* root, int k, vector<BinaryTreeNode<int>*> &result){
    if(root==nullptr or k<0) return ;
    if(k==0){
        result.push_back(root);
        return;
    }
    findKDistanceNodes(root->left, k-1, result);
    findKDistanceNodes(root->right, k-1, result);
}

int findTargetNode(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int k, vector<BinaryTreeNode<int>*> &result){
    if(!root) return -1;
    if(root==target){
        findKDistanceNodes(root, k, result);
        return 0;
    }
    int leftDis=findTargetNode(root->left, target, k, result);
    if(leftDis!=-1){
        if(leftDis+1==k){
            result.push_back(root);
        }else{
            findKDistanceNodes(root->right, k-leftDis-2, result);
        }
    return leftDis+1;
    }
    int rightDis=findTargetNode(root->right, target, k, result);
    if(rightDis!=-1){
        if(rightDis+1==k){
            result.push_back(root);
        }else{
            findKDistanceNodes(root->left, k-rightDis-2, result);
        }
    return rightDis+1;
    }

return -1;
}
