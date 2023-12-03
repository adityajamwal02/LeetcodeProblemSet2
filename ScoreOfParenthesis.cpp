/*
Given a balanced parentheses string s, return the score of the string.
The score of a balanced parentheses string is based on the following rule:
"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Example 1:
Input: s = "()"
Output: 1

Example 2:
Input: s = "(())"
Output: 2

Example 3:
Input: s = "()()"
Output: 2
*/

class Solution {
public:
    int scoreOfParentheses(string s){
        int result=0, n=s.size();
        stack<int> st;
        for(char ch : s){
            if(ch=='('){
                st.push(0);
            }else{
                if(st.top()==0) st.top()+=1;
                else{
                    int temp=0;
                    while(!st.empty() and st.top()!=0){
                        temp+=st.top();
                        st.pop();
                    }
                    if(st.empty()) st.push(temp);
                    else st.top()+=2*temp;
                }
            }
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
    return result;
    }
};
