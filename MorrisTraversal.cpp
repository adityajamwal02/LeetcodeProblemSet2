/// All Traversals (preorder, postorder, inorder) through 1 pass : morris traversal (using stack)

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

struct node *newNode(int data){
    struct node* node=(struct node*) malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

return (node);
};

void morrisTraversal(node *root,vector<int> &preorder, vector<int> &inorder, vector<int> &postorder){
    stack<pair<node*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            preorder.push_back(it.first->data);
            st.push({it.first,it.second+1});
            if(it.first->left){
                st.push({it.first->left,1});
            }
        }else if(it.second==2){
            inorder.push_back(it.first->data);
            st.push({it.first,it.second+1});
            if(it.first->right){
                st.push({it.first->right,1});
            }
        }else{
            postorder.push_back(it.first->data);
        }
    }
}

int main(){
    struct node* root=newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right = newNode(3);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    vector<int> preorder, inorder, postorder;
    morrisTraversal(root,preorder,inorder,postorder);
    cout<<"Preorder Traversal:"<<endl;
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]<<" ";
    }
    cout<<endl;
    cout<<"Inorder Traversal:"<<endl;
    for(int i=0;i<inorder.size();i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;
    cout<<"Postorder Traversal:"<<endl;
    for(int i=0;i<postorder.size();i++){
        cout<<postorder[i]<<" ";
    }


    return 0;
}
