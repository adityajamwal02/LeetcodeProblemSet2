/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return NULL;
        int prefixSum=0;
        unordered_map<int,ListNode*> mp;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        mp[0]=temp;
        while(head){
            prefixSum+=(head->val);
            if(mp.find(prefixSum)!=mp.end()){
                ListNode *start=mp[prefixSum];
                int currSum=prefixSum;
                while(start!=NULL and start!=head){
                    start=start->next;
                    currSum+=start->val;
                    if(start!=head){
                        mp.erase(currSum);
                    }
                }
            mp[prefixSum]->next=head->next;
            }else{
                mp[prefixSum]=head;
            }
        head=head->next;
        }
    return temp->next;
    }
};
