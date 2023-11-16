/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums){
        int n=nums.size(), result=0, prefixSum=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) prefixSum+=-1;
            else prefixSum+=1;
            if(mp.find(prefixSum)!=mp.end()){
                int index=mp[prefixSum];
                int length=i-index;
                result=max(result,length);
            }else{
                mp[prefixSum]=i;
            }
        }
    return result;
    }
};
