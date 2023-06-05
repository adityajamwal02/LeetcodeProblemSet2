/*
Given an string S, representing a large interger. Return the largest-valued odd integer (as a string) that is substring of the given string S.
Note : A substring is a contiguous sequence of characters within a string. Null string ("") is also a substring.

Example 1:
Input: s = "504"
Output: "5"
Explanation: The only subtring "5" is odd number.

Example 2:
Input: s = "2042"
Output: ""
Explanation: All the possible non-empty substring have even value.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxOdd() which takes the string S as input and returns the largest-valued odd integer that is substring of the given string.
Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).
*/


class Solution {
  public:
    string maxOdd(string s) {
        for(int i=s.size()-1;i>=0;i--){
            if(stoi(s.substr(i,1))%2!=0){
                return s.substr(0,i+1);
            }
        }
    return "";
    }
};
