/*
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -.

Example 1:
Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression
into postfix expression, the resultant
expression will be abcd^e-fgh*+^*+i-

Example 2:
Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation:
After converting the infix expression
into postfix expression, the resultant
expression will be ABC+*D/

Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string(Infix Expression) as a parameter and returns a string(postfix expression). The printing is done automatically by the driver code.

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).
*/



#include<bits/stdc++.h>
using namespace std;

/// Precedence of operators
int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='/' or ch=='*') return 2;
    else if(ch=='+' or ch=='-') return 1;
return -1;
}

/// Converting Infix To Postfix
string infixToPrefix(string s){
    stack<char> st;
    string result;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') {
          s[i] = ')';
          i++;
        }else if (s[i] == ')'){
          s[i] = '(';
          i++;
        }
    }
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z') or (ch>='0' and ch<='9')){
            result+=ch;
        }
        else if(ch=='('){
            st.push('(');
        }else if(ch==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() and precedence(s[i])<=precedence(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());

return result;
}


int main(){
    string infix="(p+q)*(c-d)";
    reverse(infix.begin(),infix.end());
    string prefix=infixToPrefix(infix);
    cout<<prefix<<endl;

    return 0;
}
