/*
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:
Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3

Example 2:
Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
Your Task:
Your task is to complete the given function reverseDLL(), which takes head reference as argument and should reverse the elements so that the tail becomes the new head and all pointers are correctly pointed. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).
*/

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node* reverseDLL(Node * head)
{
    Node *temp1=head, *temp2=head;
    while(temp1){
        temp2=temp1;
        temp1=temp1->next;
        swap(temp2->next,temp2->prev);
    }
    return temp2;
}
