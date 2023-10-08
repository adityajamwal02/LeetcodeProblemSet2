/*
A parentheses string is valid if and only if:
It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3
*/


class Solution {
public:
    int minAddToMakeValid(string s){
        int n=s.size(), result=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(')');
            else{
                if(!st.empty()) st.pop();
                else result++;
            }

        }
        while(!st.empty()){
            result++;
            st.pop();
        }
    return result;
    }
};

