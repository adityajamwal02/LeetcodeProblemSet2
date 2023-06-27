/*
Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Example 1:
Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output:
1 2 3 4 6 8 9
Explaination:
All the distinct numbers from two lists, when sorted forms the list in the output.

Example 2:
Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output:
1 2 4 5 6 7
Explaination:
All the distinct numbers from two lists, when sorted forms the list in the output.
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Expected Time Complexity: O((N+M)*Log(N+M))
Expected Auxiliary Space: O(N+M)
*/

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
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        int n=0, m=0;
        Node *temp=head1;
        set<int> result;
        while(temp){
            result.insert(temp->data);
            temp=temp->next;
        }
        temp=head2;
        while(temp){
            result.insert(temp->data);
            temp=temp->next;
        }
        Node *head= new Node(-1);
        Node *temp1=head;
        for(auto it :result){
            Node *newNode=new Node(it);
            temp1->next=newNode;
            temp1=newNode;
        }
    return head->next;
    }
};
