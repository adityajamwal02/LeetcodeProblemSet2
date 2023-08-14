/*
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
Return the head of the linked list after doubling it.

Example 1:
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr, *curr=head;
        while(curr!=nullptr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
    return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        head=reverseList(head);
        ListNode *curr=head, *newHead=nullptr;
        int carry=0;
        while(curr!=nullptr){
            int sum=curr->val*2+carry;
            carry=sum/10;
            sum%=10;
            if(newHead==nullptr){
                newHead=new ListNode(sum);
            }else{
                ListNode* newNode=new ListNode(sum);
                newNode->next=newHead;
                newHead=newNode;
            }
            curr=curr->next;
        }
        if(carry>0){
            ListNode* newNode=new ListNode(carry);
            newNode->next=newHead;
            newHead=newNode;
        }
    return newHead;
    }
};
