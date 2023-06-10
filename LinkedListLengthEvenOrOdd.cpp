/*
Given a linked list of size N, your task is to complete the function isLengthEvenOrOdd() which contains head of the linked list and check whether the length of linked list is even or odd.

Input:
The input line contains T, denoting the number of testcases. Each testcase contains two lines. the first line contains N(size of the linked list). the second line contains N elements of the linked list separated by space.

Output:
For each testcase in new line, print "even"(without quotes) if the length is even else "odd"(without quotes) if the length is odd.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to  complete the function isLengthEvenOrOdd() which takes head of the linked list as input parameter and returns 0 if the length of the linked list is even otherwise returns 1.
*/

/*structure of a node of the linked list is as
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
// Function should return 0 is length is even else return 1
int isLengthEvenOrOdd(struct Node* head)
{
    int i=0;
    if(!head) return 0;
    while(head!=NULL and head->next!=NULL){
        i++;
        head=head->next;
    }
    return i%2==0 ? 1 : 0;
}
