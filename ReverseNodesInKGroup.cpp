/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k==1)
            return head;
        ListNode*temp=new ListNode();
        temp->next=head;
        ListNode* curr=temp, *nex=temp, *prev=temp;
        int count=0;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        while(count>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            count=count-k;
        }
    return temp->next;
    }
};


 Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    {
        struct node *c=head,*p=NULL,*n=NULL;
        int x=k;
        while(c && x--){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        if(n) head->next=reverse(n,k);
    return p;
    }
};
