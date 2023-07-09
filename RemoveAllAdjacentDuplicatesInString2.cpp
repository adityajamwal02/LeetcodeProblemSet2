/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
*/


/// Stack Based Solution
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        int counter=0; char prev=s[0];
        string result="";
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(st.top()==prev) counter++;
            else{
                prev=st.top();
                counter=1;
            }
            if(counter==k){
                while(counter--){
                    st.pop();
                }
            }
            if(counter<=0 and st.size()>0){
                prev=st.top();
                vector<char> temp;
                counter=0;
                while(st.size()>0 and st.top()==prev){
                    counter++;
                    temp.push_back(st.top());
                    st.pop();
                }
                for(auto it : temp){
                    st.push(it);
                }
            }
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
    reverse(result.begin(),result.end());
    return result;
    }

};
