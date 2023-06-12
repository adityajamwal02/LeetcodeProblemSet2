/*
You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size(), i=0, j=0;
        vector<string> result;
        if(n==0) return result;
        while(j<n){
            if(j+1<n and nums[j+1]==nums[j]+1){
                j++;
            }else{
                string temp = (i!=j) ? to_string(nums[i])+"->"+to_string(nums[j]) : to_string(nums[i]);
                result.push_back(temp);
                i=j+1;
                j++;
            }
        }
    return result;
    }
};
