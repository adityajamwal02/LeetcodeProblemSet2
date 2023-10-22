/*
You are given an array of integers nums (0-indexed) and an integer k.
The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
Return the maximum possible score of a good subarray.

Example 1:
Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.

Example 2:
Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k){
        int n=nums.size(), left=k, right=k, result=nums[k], mini=nums[k];
        while(left>0 or right<n){
            int leftVal= (left>0) ? nums[left-1] : 0;
            int rightVal= (right+1<n) ? nums[right+1] : 0;
            if(leftVal>rightVal){
                left-=1;
                mini=min(mini,leftVal);
            }else{
                right+=1;
                mini=min(mini,rightVal);
            }
        result=max(result,mini*(right-left+1));
        }
    return result;
    }
};
