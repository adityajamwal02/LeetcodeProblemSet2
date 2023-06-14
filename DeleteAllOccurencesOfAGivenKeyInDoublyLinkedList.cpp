/*
You are given the head of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key and return the new DLL.

Example:
Input:
2<->2<->10<->8<->4<->2<->5<->2
2
Output:
10<->8<->4<->5
Explanation:
All Occurences of 2 have been deleted.
Your Task:

Complete the function void deleteAllOccurOfX(struct Node** head_ref, int key), which takes the reference of the head pointer and an integer value key. Delete all occurrences of the key from the given DLL.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

/// Solution 1

/* refering head to head_ref and looping till head reaches end and covers all head values equals x, loop over from head if temp==x the check the prev of
    temp, if existing, make the previous of temp pointing to the next of temp, similarly, check for next of temp, if not null then make previous of temp's
    next as temp's prev. Else if the value doesnt equal x, simply move temp to next, point to next. and continue; */

void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node *head=*head_ref;
        while(head and head->data==x){
            head=head->next;
        }
        Node *temp=head;
        while(temp){
            if(temp->data==x){
                if(temp->prev){
                    temp->prev->next=temp->next;
                }
                if(temp->next){
                    temp->next->prev=temp->prev;
                }
            }
        temp=temp->next;
        }
    *head_ref=head;
    }


/// Solution 2 : Generalize Approach

// User function Template for C++


/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:

    void deleteNode(Node *&head, Node *&temp)
    {
        if(temp==head){
            head=head->next;
        }
        if(temp->prev){
            temp->prev->next=temp->next;
        }
        if(temp->next){
            temp->next->prev=temp->prev;
        }
        delete temp;
    }

    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node *temp=*head_ref;
        while(temp){
            Node *curr=temp->next;
            if(temp->data==x){
                deleteNode(*head_ref, temp);
            }
            temp=curr;
        }
    }
};
