/*
You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
*/

/// Extra Space Solution (Vector --> 2 Ways, vector<int> and traverse)

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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        int n=nums.size();

        swap(nums[k-1],nums[n-k]);
        ListNode* node = new ListNode();
        ListNode* dummy = node;

        for(int i=0;i<nums.size();i++){
            ListNode* temp=new ListNode(nums[i]);
            node->next=temp;
            node=node->next;
        }
    return dummy->next;
    }
};

/// vector<ListNode*>

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> result;
        while(head){
            result.push_back(head);
            head=head->next;
        }
        int n=result.size();
        swap(result[k-1]->val,result[n-k]->val);
    return result[0];
    }
};


/// Optimal Solution (No vector)

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(--k){
            fast=fast->next;
        }
        ListNode* temp=fast;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        swap(temp->val, slow->val);
    return head;
    }
};


