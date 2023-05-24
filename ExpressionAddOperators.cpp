/*
Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between the digits of S so that the resultant expression evaluates to the target value.
Note: Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine. It is allowed to not insert any of the operators.

Example 1:
Input:
S = "123"
target = 6
Output: { "1*2*3", "1+2+3"}
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:
Input:
S = "3456237490"
target = 9191
Output: { }
Explanation: There are no expressions that can be created from "3456237490"  to evaluate to 9191.

Example 3:
Input:
S = "12"
target = 12
Output: { "12"}
Explanation: S itself matches the target. No other strings are possible.
Your Task:
You don't need to read input or print anything. Your task is to complete the function addOperators() which takes string S and integer target as parameters and returns a list of strings that contains all valid possibilities.

Expected Time Complexity: O(|S|*4|S|)
Expected Auxiliary Space: O(|s|*3|S|)
*/

class Solution {
  public:

    vector<string> result;
    int target;
    string s;

    void helper(int index, long prev, long val, string expression){
        if(index==s.size()){
            if(val==target){
                result.push_back(expression);
                return;
            }
        }
        int n=s.size();
        string new_string="";
        int curr=0;
        for(int i=index;i<n;i++){
            if(i>index and s[index]=='0'){
                return;
            }
            new_string+=s[i];
            curr=curr*10+s[i]-'0';
            if(index==0){
                helper(i+1,curr,curr,expression+new_string);
                continue;
            }
            helper(i+1,curr,val+curr,expression+"+"+new_string);
            helper(i+1,-curr,val-curr,expression+"-"+new_string);
            helper(i+1,prev*curr,val-prev+prev*curr,expression+"*"+new_string);
        }
    }

    vector<string> addOperators(string S, int target) {
        this->target=target;
        this->s=S;
        helper(0,0,0,"");
    return result;
    }
};
