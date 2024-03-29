/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation:
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation:
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation:
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
*/

/// string solution

class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter=0;
        string result="";
        for(char c : s){
            if(c=='('){
                if(counter>0){
                    result+=c;
                }
                counter++;
            }else{
                counter--;
                if(counter>0){
                    result+=c;
                }
            }
        }
    return result;
    }
};


/// Stack Solution

string removeOuterParentheses(string s) {
    string result = "";
    stack<char> parenthesesStack;
    for (char c : s) {
        if (c == '(') {
            if (!parenthesesStack.empty()) {
                result += c; // Add '(' if it is not the outermost parentheses
            }
            parenthesesStack.push(c); // Push '(' onto the stack
        } else {
            parenthesesStack.pop(); // Pop '(' from the stack

            if (!parenthesesStack.empty()) {
                result += c; // Add ')' if it is not the outermost parentheses
            }
        }
    }
    return result;
}
