/*
Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example 1:
Input:
LinkedList = 1->2->4
(the first and last node is connected,
i.e. 4 --> 1)
data = 2
Output: 1 2 2 4

Example 2:
Input:
LinkedList = 1->4->7->9
(the first and last node is connected,
i.e. 9 --> 1)
data = 5
Output: 1 4 5 7 9
Your Task:
The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linkedlist.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

class Solution
{
    public:
    Node *sortedInsert(Node* head, int key){
        Node *newNode = new Node(key);
        if(!head) head=newNode;
        Node *curr=head, *prev=NULL;
        if(head->data>=key){
            do{
                prev=curr;
                curr=curr->next;
            }while(curr!=head);
            head=newNode;
        }else{
            do{
                prev=curr;
                curr=curr->next;
            }while(curr!=head and curr->data < key);
        }
        newNode->next=prev->next;
        prev->next=newNode;
    return head;
    }
};
