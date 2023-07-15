/*

*/


#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

vector<int> findNextGreaterNodeList(Node* head)
{
	vector<int> nums, result;
	Node *temp=head;
	while(temp){
		nums.push_back(temp->data);
		temp=temp->next;
	}
	stack<int> st;
	for(int i=nums.size()-1;i>=0;i--){
		while(!st.empty() and nums[i]>=st.top()){
			st.pop();
		}
		if(!st.empty()) result.push_back(st.top());
		else result.push_back(0);

	st.push(nums[i]);
	}
	reverse(result.begin(),result.end());
return result;
}

