/*
You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
Return the number of non-empty subarrays in nums that have a median equal to k.
Note:
The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [3,2,1,4,5], k = 4
Output: 3
Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].

Example 2:
Input: nums = [2,3,1], k = 3
Output: 1
Explanation: [3] is the only subarray that has a median equal to 3.
*/

/// Prefix Sum + Hashmap

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int counter=0, found=0, sum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto num : nums){
            if(num==k) found=1;
            else{
                if(num<k){
                    sum+=-1;
                }else{
                    sum+=1;
                }
            }
            if(found) counter+=mp[sum-1]+mp[sum];
            else mp[sum]++;
        }
    return counter;
    }
};

