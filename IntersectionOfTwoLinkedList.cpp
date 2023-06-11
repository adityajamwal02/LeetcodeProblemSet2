/*
Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Example 1:
Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
Your Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameter and returns the head of intersection list. Returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in input list 1.

Constraints:
1 <= n,m <= 104

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)
*/

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        map<int, int> mp;
        Node* h1 = head1;
        Node* h2 = head2;
        while(h1) {
            mp[h1->data]++;
            h1 = h1->next;
        }
        while(h2) {
            mp[h2->data]++;
            h2 = h2->next;
        }
        h1 = head1;
        Node* res = new Node(0);
        Node* temp = res;
        while(h1) {
            if(mp[h1->data] == 2) {
                Node* newNode = new Node(h1->data);
                temp->next = newNode;
                temp = temp->next;
            }
            h1 = h1->next;
        }
        return res->next;
    }
};
