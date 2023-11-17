/*
Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
Return the shortest such subarray and output its length.

Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
Input: nums = [1,2,3,4]
Output: 0

Example 3:
Input: nums = [1]
Output: 0
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums){
        int n=nums.size(), result=-1, left=-1, right=-1, maxVal=INT_MIN, minVal=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                left=i;         // starting index of the unsorted part
                break;
            }
        }
        if(left==-1) return 0; // already sorted
        for(int i=n-1;i>=0;i--){
            if(nums[i]<nums[i-1]){
                right=i;
                break;
            }
        }
        // Look for shortest in the unsorted window
        for(int i=left;i<=right;i++){
            maxVal=max(maxVal,nums[i]);
            minVal=min(minVal,nums[i]);
        }
        for(int i=0;i<left;i++) if(nums[i]>minVal) left=i;
        for(int i=right+1;i<n;i++) if(nums[i]<maxVal) right=i;

    return right-left+1;
    }
};
