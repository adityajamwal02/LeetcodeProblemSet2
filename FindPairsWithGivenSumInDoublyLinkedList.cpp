/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

Example 1:
Input:
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs
(1, 6) and (2,5) with sum 7.

Example 2:
Input:
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> result;
        Node* temp1=head, *temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        while(temp1->data<temp2->data){
            if((temp1->data+temp2->data)==target){
                result.push_back({temp1->data,temp2->data});
                temp1=temp1->next;
                temp2=temp2->prev;
            }else if((temp1->data+temp2->data)<target){
                temp1=temp1->next;
            }else{
                temp2=temp2->prev;
            }
        }
    return result;
    }
};
