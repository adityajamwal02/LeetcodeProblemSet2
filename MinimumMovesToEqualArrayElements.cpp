/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment n - 1 elements of the array by 1.

Example 1:
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Example 2:
Input: nums = [1,1,1]
Output: 0
*/

class Solution {
public:
    int minMoves(vector<int>& nums){
        int n=nums.size(), minVal=*min_element(nums.begin(),nums.end()), maxVal=*max_element(nums.begin(),nums.end());
        if(maxVal==minVal) return 0;
        int result=0, diff=0;
        for(int i=0;i<n;i++){
            diff=nums[i]-minVal;
            result+=(diff);
        }
    return result;
    }
};
