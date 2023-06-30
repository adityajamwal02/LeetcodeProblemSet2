/*
Given a string s, remove all its adjacent duplicate characters recursively.
Note: For some test cases, the resultant string would be an empty string. In that case, the function should return the empty string only.

Example 1:
Input:
S = "geeksforgeek"
Output: "gksforgk"
Explanation:
g(ee)ksforg(ee)k -> gksforgk

Example 2:
Input:
S = "abccbccba"
Output: ""
Explanation:
ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

Your Task:
You don't need to read input or print anything. Your task is to complete the function rremove() which takes the string S as input parameter and returns the resultant string.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)
*/

class Solution{
public:
    string rremove(string s){
        int n=s.size();
        string result="";
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1] or s[i]==s[i-1]){
                continue;
            }else{
                result.push_back(s[i]);
            }
        }
        if(result==s) return result;
    return rremove(result);
    }
};
