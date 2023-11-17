/*
You are given an integer array nums and an integer k. Append k unique positive integers that do not appear in nums to nums such that the resulting total sum is minimum.
Return the sum of the k integers appended to nums.

Example 1:
Input: nums = [1,4,25,10,25], k = 2
Output: 5
Explanation: The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.

Example 2:
Input: nums = [5,6], k = 6
Output: 25
Explanation: The six unique positive integers that do not appear in nums which we append are 1, 2, 3, 4, 7, and 8.
The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which is the minimum.
The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so we return 25.
*/

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k){
        long long result=0;
        int n=nums.size(), curr=0, prev=0, index=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n and k>0;i++){
            if(i-1<0) prev=0;
            else prev=nums[i-1];
            curr=nums[i];
            if(curr-prev>1){
                if(curr-prev-1>k)
                    curr=prev+k+1;
            result+=((1LL*curr*(curr-1))/2)-((1LL*prev*(prev+1))/2);
            k=k-(curr-prev-1);
            }
        }
        if(k>0){
            prev=nums.back(), curr=prev+k+1;
            result+=((1LL*curr*(curr-1))/2)-((1LL*prev*(prev+1))/2);
            k=k-(curr-prev-1);
        }

    return result;
    }
};
