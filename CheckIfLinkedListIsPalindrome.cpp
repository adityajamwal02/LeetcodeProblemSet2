/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

Example 2:
Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)
*/

/// No Linear Extra Space

class Solution{
  public:
    //Function to reverse the LL
    Node* makeReverse(Node *head){
        if(!head or !head->next) return head;
        Node *reverse=makeReverse(head->next);
        head->next->next=head;
        head->next=NULL;
    return reverse;
    }

    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(!head or !head->next) return true;
        Node *slow=head;
        Node *fast=head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *reverse=makeReverse(slow->next);
        slow=head;
        while(slow and reverse){
            if(slow->data!=reverse->data) return false;
            slow=slow->next;
            reverse=reverse->next;
        }
    return true;
    }
};
