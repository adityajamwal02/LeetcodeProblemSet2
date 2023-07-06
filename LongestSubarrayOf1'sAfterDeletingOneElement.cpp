/*
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

*/


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Taken k here as 1, but making it generalize form for any k
        int i=0, j=0, n=nums.size(), zerocounter=0, maxLen=INT_MIN, k=1;
        while(j<n){
            if(nums[j]==0){
                zerocounter++;
            }
            while(zerocounter>k){
                if(nums[i]==0) zerocounter--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        j++;
        }
        if(maxLen==n) return maxLen-k;
        if(maxLen==INT_MIN) maxLen=0;
    return maxLen-k;
    }
};
