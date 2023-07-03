/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
Output: 15
*/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        long long n=nums.size(), counter=0, prefixSum=0;
        long long presum[n+1];
        for(int i=0;i<n+1;i++){
            presum[i]=0;
        }
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int leftover=prefixSum-goal;
            if(leftover>=0) counter+=presum[leftover];
            if(prefixSum==goal) counter++;
            presum[prefixSum]+=1;
        }
    return counter;
    }
};


/// Sliding Window

class Solution {
public:
    int atmostSubarray(vector<int> &nums, int target){
        if(target<0) return 0;
        int i=0, j=0, result=0, sum=0, n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            result+=(j-i+1);
        j++;
        }
    return result;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostSubarray(nums,goal)-atmostSubarray(nums,goals-1);
    }
};


