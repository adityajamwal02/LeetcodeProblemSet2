/*
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:
Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

Example 2:
Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument, and returns the head of the rotated linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

/// Brute Approach

node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}


/// Using Vector (Rotate Array Concept)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        vector<int> result;
        ListNode *temp=head;
        while(temp){
            result.push_back(temp->val);
            temp=temp->next;
        }
        int n=result.size();
        k=k%n;
        reverse(result.begin(),result.begin()+n-k);
        reverse(result.begin()+n-k,result.end());
        reverse(result.begin(),result.end());
        ListNode *ans=new ListNode(-1);
        ListNode *curr=ans;
        for(int i=0;i<n;i++){
            ListNode *temp1=new ListNode(result[i]);
            curr->next=temp1;
            curr=curr->next;
        }
    return ans->next;
    }
};

/// Optimal Solution

node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    head = temp->next;
    temp->next = NULL;

    return head;
}


/// Counter Clockwise Rotate:

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
          Node *temp=head,*last=head;

        int cnt=0;

        while(last->next!=NULL)
            last=last->next;

        while(cnt<k)
        {
            last->next=temp;
            last=temp;
            temp=temp->next;
            last->next=NULL;
            cnt++;
        }

        return temp;
    }
};
