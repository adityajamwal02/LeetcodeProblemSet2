/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.
NOTE: Don't create a new linked list, instead rearrange the provided one.

Example 1:
Input:
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers
so they appear first and 17,15,9 are odd
numbers that appear later.

Example 2:
Input:
N = 4
Link List:
1 -> 3 -> 5 -> 7

Output: 1 3 5 7
Explaination: There is no even number.
So ne need for modification.

Your Task:
You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and returns the head of modified link list. Don't create a new linked list, instead rearrange the provided one.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/


/// With extra space

//User function template for C++

/*
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
    Node* divide(int N, Node *head){
        // if(!head or !head->next) return head;
        Node *temp=head;
        Node *ans=new Node(-1);
        Node *result=ans;
        while(temp!=NULL){
            if(temp->data%2==0){
                Node *curr=new Node(temp->data);
                result->next=curr;
                result=result->next;
            }
        temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->data%2!=0){
                Node *curr=new Node(temp->data);
                result->next=curr;
                result=result->next;
            }
        temp=temp->next;
        }
    return ans->next;
    }
};


/// Without extra space

class Solution{
public:
    Node* divide(int N, Node *head){
        Node* even = NULL;
        Node* e = NULL;
        Node* odd = NULL;
        Node* o = NULL;

        while(head){
            if(head->data % 2 == 0){
                if(even == NULL){
                    even = head;
                    e = head;
                }
                else{
                    e->next = head;
                    e = e->next;
                }
            }
            else{
                if(odd == NULL){
                    odd = head;
                    o = head;
                }
                else{
                    o->next = head;
                    o = o->next;
                }
            }
            head = head->next;
        }

        if(e) e->next = odd;
        if(o) o->next = NULL;
        if(even) return even;
        return odd;
    }
};
