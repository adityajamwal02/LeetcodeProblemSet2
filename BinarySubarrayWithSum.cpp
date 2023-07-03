/*
Given a binary array arr of size N and an integer target, return the number of non-empty subarrays with a sum equal to target.
Note : A subarray is the contiguous part of the array.

Example 1:
Input:
N = 5
target = 2
arr[ ] = {1, 0, 1, 0, 1}
Output: 4
Explanation: The 4 subarrays are:
{1, 0, 1, _, _}
{1, 0, 1, 0, _}
{_, 0, 1, 0, 1}
{_, _, 1, 0, 1}

Example 2:
Input:
N = 5
target = 5
arr[ ] = {1, 1, 0, 1, 1}
Output: 0
Explanation: There is no subarray with sum equal to target.

Your Task:
You don't need to read input or print anything. Your task is to complete the function numberOfSubarrays() which takes the array arr, interger N and an integer target as input and returns the number of subarrays with a sum equal to target.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

/// Hashmap Solution

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

/// Sliding Window Approach (IDEA: get atmostsum (sum<=goal) and then remove sum<goal)

class Solution {
public:
    int atmostSubarray(vector<int> &nums, int target){
        if(target<0) return 0;
        int i=0, j=0, result=0, sum=0, n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(sum>target){
                sum-=nums[i];
                i++;
            }
            result+=(j-i+1);
        j++;
        }
    return result;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostSubarray(nums,goal)-atmostSubarray(nums,goal-1);
    }
};
