/*
You are given a 0-indexed array nums that consists of n distinct positive integers. Apply m operations to this array, where in the ith operation you replace the number operations[i][0] with operations[i][1].
It is guaranteed that in the ith operation:
operations[i][0] exists in nums.
operations[i][1] does not exist in nums.
Return the array obtained after applying all the operations.

Example 1:
Input: nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
Output: [3,2,7,1]
Explanation: We perform the following operations on nums:
- Replace the number 1 with 3. nums becomes [3,2,4,6].
- Replace the number 4 with 7. nums becomes [3,2,7,6].
- Replace the number 6 with 1. nums becomes [3,2,7,1].
We return the final array [3,2,7,1].

Example 2:
Input: nums = [1,2], operations = [[1,3],[2,1],[3,2]]
Output: [2,1]
Explanation: We perform the following operations to nums:
- Replace the number 1 with 3. nums becomes [3,2].
- Replace the number 2 with 1. nums becomes [3,1].
- Replace the number 3 with 2. nums becomes [2,1].
We return the array [2,1].
*/

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations){
        unordered_map<int,int> mp1, mp2;
        int n=nums.size(), m=operations.size();
        for(int i=0;i<n;i++){
            mp1[i]=nums[i];
            mp2[nums[i]]=i;
        }
        for(int i=0;i<m;i++){
            int num1=operations[i][0], num2=operations[i][1], index=mp2[num1];
            mp1[index]=num2;
            mp2[num2]=index;
        }
        for(auto it : mp1){
            nums[it.first]=it.second;
        }
    return nums;
    }
};
