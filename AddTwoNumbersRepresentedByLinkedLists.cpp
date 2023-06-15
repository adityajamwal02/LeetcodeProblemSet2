/*
Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.
For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

Example 2:
Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.
*/


/// Convert to string and then handle the addition


class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    string revstr(string a,string b)
    {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n=a.length();
        int m=b.length();
        int r=0,i=0;
        string res="";
        while(i<n || i<m)
        {
            int x= (i<n) ? (a[i]-'0'):0;
            int y = (i<m) ? (b[i]-'0'):0;
            int q = (x+y+r)%10;
            r = (x+y+r)/10;
            res = res+to_string(q);
            i++;
        }
        res+= (r==0)?"":to_string(r);
        reverse(res.begin(),res.end());
    return res;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *curr = first;
        string a="",b="";
        while(curr!=NULL)
        {
            a+=to_string(curr->data);
            curr=curr->next;
        }
        curr=second;
        while(curr!=NULL)
        {
            b+=to_string(curr->data);
            curr=curr->next;
        }
        string res= revstr(a,b);
        if(res.size()==0) return NULL;
        Node *head= new Node(res[0]-'0');
        curr=head;
        int m=1;
        while(m<res.length())
        {
            int c=res[m]-'0';
            Node* temp = new Node(c);
            curr->next=temp;
            curr= temp;
            m++;

        }
    return head;
    }
};

/// Efficient direct solution

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *result=new ListNode();
        ListNode *temp=result;
        int carry=0;
        while((l1 or l2) or carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
    return result->next;
    }
};

/// Stack based solution (Efficient but space compromised)

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int n=0, m=0;
        Node *temp1=first, *temp2=second;
        while(temp1){
            n++;
            temp1=temp1->next;
        }
        while(temp2){
            m++;
            temp2=temp2->next;
        }
        temp1=first, temp2=second;
        stack<int> st;
        stack<Node*> result;
        result.push(NULL);
        if(n>=m){
            for(int i=0;i<n-m;i++){
                st.push(temp1->data);
                temp1=temp1->next;
            }
        }else{
            for(int i=0;i<m-n;i++){
                st.push(temp2->data);
                temp2=temp2->next;
            }
        }
        while(temp1){
            st.push(temp1->data+temp2->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(!st.empty()){
            int num=st.top();
            Node *x=new Node(num%10);
            x->next=result.top();
            result.push(x);
            st.pop();
            if(num>9){
                if(st.empty()) st.push(1);
                else st.top()+=1;;
            }
        }
    return result.top();
    }
};
