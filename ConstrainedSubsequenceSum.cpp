/*
Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Example 2:
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

Example 3:
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
*/

/// Deqeue based Solution

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k){
        int n=nums.size(), maxi=nums[0];
        vector<int> temp(nums);
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() and dq.front()<i-k){
                dq.pop_front();
            }
            if(!dq.empty()){
                temp[i]=max(temp[i],nums[i]+temp[dq.front()]);
            }
            while(!dq.empty() and temp[i]>=temp[dq.back()]){
                dq.pop_back();
            }
        dq.push_back(i);
        maxi=max(maxi,temp[i]);
        }
    return maxi;
    }
};
