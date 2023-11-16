/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

Example 1:
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
*/


class Solution {
public:
    string helper(string str, int n, unordered_set<string> &st){
        if(str.size()==n){
            if(st.find(str)==st.end())
                return str;

        return "";
        }
        string temp0=helper(str+"0",n,st);
        if(temp0.size()>0) return temp0;

    return helper(str+"1",n,st);
    }

    string findDifferentBinaryString(vector<string>& nums){
        int n=nums.size();
        unordered_set<string> st(nums.begin(),nums.end());

    return helper("",n,st);
    }
};
