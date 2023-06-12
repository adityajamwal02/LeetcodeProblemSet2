/*
You are given a string s and two integers x and y. You can perform two types of operations any number of times.
Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

Example 1:
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
*/


class Solution {
public:
    int helper(string &s, int x, int y, char ch1, char ch2){
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==ch2){
                if(!st.empty() and st.top()==ch1){
                    st.pop();
                    ans+=x;
                }else st.push(s[i]);
            }else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
    return ans;
    }

    int maximumGain(string s, int x, int y) {
        int result=0;
        if(x>y){
            result=helper(s,x,y,'a','b');
            result+=helper(s,y,x,'b','a');
        }else{
            result=helper(s,y,x,'b','a');
            result+=helper(s,x,y,'a','b');
        }
    return result;
    }
};
