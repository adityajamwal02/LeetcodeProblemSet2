/*
Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.

Example 1:
Tree =
        4
      /   \
     2     6
    / \   / \
   1   3 5   7

N = 4
Values to be deleted = {4,1,3,6}

Input: Value to be deleted = 4
Output:
        5
      /   \
     2     6
    / \     \
   1   3     7

Input: Value to be deleted = 1
Output:
        5
      /   \
     2     6
      \     \
       3     7

Input: Value to be deleted = 3
Output:
        5
      /   \
     2     6
            \
             7

Input: Value to be deleted = 6
Output:
        5
      /   \
     2     7

Your Task:
You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

Note: The tree will be checked after each deletion.
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
If instead all deletion are successful, inorder traversal of tree will be printed.
If every single node is deleted from tree, 'null' will be printed.

Expected Time Complexity: O(height of tree)
Expected Auxiliary Space: O(height of tree)
*/

/// Height Concept + Self-Balancing (Left/Right Rotate) + inorderSuccessor + Recursion

//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
}

Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    setHeights(root);
    return root;
}

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

struct Node* deleteNode(struct Node* root, int data);

int main()
{
	int t;
	cin>>t;
	getchar();

	while(t--)
	{
		string s;
		getline(cin,s);
		Node* root = buildTree(s);

		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];

		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);

			if( !isBalancedBST(root) )
				break;
		}

		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;

		getline(cin,s); // to deal with newline char
	}
	return 1;
}

// } Driver Code Ends


/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};
*/

int height(Node *root){
    if(!root) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
return 1+max(lh,rh);
}

int getBalance(Node *root){
    if(!root) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
return lh-rh;
}

Node *leftRotate(Node *root){
    Node *temp1=root->right;
    Node *temp2=temp1->left;
    temp1->left=root;
    root->right=temp2;
return temp1;
}

Node *rightRotate(Node *root){
    Node *temp1=root->left;
    Node *temp2=temp1->right;
    temp1->right=root;
    root->left=temp2;
return temp1;
}


Node *inorderSuccessor(Node *root){
    while(root and root->left){
        root=root->left;
    }
return root;
}


Node* deleteNode(Node* root, int data)
{
    if(!root) return NULL;
    if(root->data > data){
        root->left=deleteNode(root->left,data);
    }
    else if(root->data < data){
        root->right=deleteNode(root->right,data);
    }else{
        if(!root->left){
            Node *temp=root;
            root=root->right;
            delete temp;
        }else if(!root->right){
            Node *temp=root;
            root=root->left;
            delete temp;
        }else{
            Node *temp=inorderSuccessor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    if(!root) return root;
    int balance=getBalance(root);
    if(balance>1 and getBalance(root->left)>=0){
        return rightRotate(root);
    }else if(balance>1 and getBalance(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }else if(balance<-1 and getBalance(root->right)<=0){
        return leftRotate(root);
    }else if(balance<-1 and getBalance(root->right)>0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
return root;
}
