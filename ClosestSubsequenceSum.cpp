/*
You are given an integer array nums and an integer goal.
You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
Return the minimum possible value of abs(sum - goal).
Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

Example 1:
Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.

Example 2:
Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.

Example 3:
Input: nums = [1,2,3], goal = -7
Output: 7
*/


class Solution {
public:
    vector<int> generateSumCombinations(int n, vector<int> &arr){
        vector<int> result;
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=arr[j];
                }
            }
        result.push_back(sum);
        }
    return result;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size(), result=INT_MAX;
        if(n==1) return min(abs(goal),abs(goal-nums[0]));

        vector<int> nums1(nums.begin(),nums.begin()+n/2);
        vector<int> nums2(nums.begin()+n/2,nums.end());

        vector<int> arr1=generateSumCombinations(nums1.size(),nums1);
        vector<int> arr2=generateSumCombinations(nums2.size(),nums2);
        sort(arr2.begin(),arr2.end());

        for(int i=0;i<arr1.size();i++){
            int lowerBound=lower_bound(arr2.begin(),arr2.end(),goal-arr1[i])-arr2.begin();
            if(lowerBound>0){
                int val=abs(goal-arr2[lowerBound-1]-arr1[i]);
                result=min(result,val);
            }
            if(lowerBound<arr2.size()){
                int val=abs(goal-arr2[lowerBound]-arr1[i]);
                result=min(result,val);
            }
        }
    return result;
    }
};

