/*
Given a singly linked list containing N nodes. Modify the Linked list as follows:
1. Modify the value of the first half nodes such that 1st node's new value is equal to the value of the last node minus the first node's current value, 2nd node's new value is equal to the second last nodes value minus 2nd nodes current value, likewise for first half nodes.
2. Replace the second half of nodes with the initial values of the first half nodes(values before modifying the nodes).
3. If N is odd then the value of the middle node remains unchanged.

Example 1:
Input:
N = 5
linked list = 10 -> 4 -> 5 -> 3 -> 6
Output:
-4 -1 5 4 10
Explanation:
For first half nodes modified list will be:
-4 -> -1 -> 5 -> 3 -> 6
For second half nodes modified list will be:
-4 -> -1 -> 5 -> 4 -> 10

Example 2:
Input:
N = 6
linked list = 2 -> 9 -> 8 -> 12 -> 7 -> 10
Output:
8 -2 4 8 9 2
Explanation:
After modifying the linked list as required,
we have a new linked list containing the elements as
8 -> -2 -> 4 -> 8 -> 9 -> 2.
YourTask:
The task is to complete the function modifyTheList() which should modify the list as required.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
-105  <= Node->data <= 105
*/

/// Additional Space:

/*Complete the function below
Node is as follows:
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
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        vector<int> nums;
        Node* temp=head;
        while(temp!=NULL){
            nums.push_back(temp->data);
            temp=temp->next;
        }
        int n=nums.size();
        int i=0, j=n-1;
        while(i<j){
            int temp=nums[i];
            nums[i]=nums[j]-temp;
            nums[j]=temp;
            i++;
            j--;
        }
        i=0;
        temp=head;
        while(temp!=NULL){
            temp->data=nums[i];
            temp=temp->next;
            i++;
        }
    return head;
    }
};

/// O(1) space

    Node *rev( Node *head)
     {
          Node *pre=NULL;
           Node *cur=head;
         while(cur!=NULL)
         {
              Node *nex=cur->next;
              cur->next=pre;
              pre=cur;
              cur=nex;
         }
         return pre;
     }
    struct Node* modifyTheList(struct Node *head)
    {
         Node * slow=head,*fast=head->next;
         while( fast!=NULL && fast->next!=NULL)
         {
             slow=slow->next;
             fast=fast->next->next;
         }
          Node * temp2=slow->next;
                  slow->next=NULL;

         Node* temp=rev(temp2);
           Node* copy=temp;
           Node * he=head;
           Node *pre=NULL;
          while(temp!=NULL )
          {
              pre=temp;
            temp->data= (temp->data) - (he->data);
              temp=temp->next;
             he=he->next;
          }
          Node * temp1=rev(head);
          pre->next=temp1;
          return  copy;

    }


