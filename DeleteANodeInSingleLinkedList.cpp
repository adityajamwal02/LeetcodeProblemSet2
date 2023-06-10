/*
Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:
Input: 1 -> 3 -> 4
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3.

Example 2:
Input: 1 -> 5 -> 2 -> 9
x = 2
Output: 1 -> 2 -> 9
Explanation:
After deleting the node at 2nd
position (1-based indexing), the
linked list is as 1 -> 2 -> 9.

Your task: Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the linked list and an integer x. The function returns the head of the modified linked list.
*/


/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    if(x==1){
        Node *curr=head;
        head=head->next;
        curr->next=nullptr;
        delete curr;
    return head;
    }

    Node *curr=head, *prev=nullptr;
    x=x-1;
    while(x--){
        prev=curr;
        curr=curr->next;
    }
    Node *temp=curr;
    curr=curr->next;
    prev->next=curr;
    temp->next=nullptr;
    delete temp;
    return head;
}


/// Optimal + clean Code

Node* deleteNode(Node *head,int x)
{
   Node *temp=head;
   if(x==1){
       head=head->next;
   }
   for(int i=1;i<x-1;i++){
       temp=temp->next;
   }
   temp->next=temp->next->next;
   return head;
}
