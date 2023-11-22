/*
Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.
A quadruplet (i, j, k, l) is increasing if:
0 <= i < j < k < l < n, and
nums[i] < nums[k] < nums[j] < nums[l].

Example 1:
Input: nums = [1,3,2,4,5]
Output: 2
Explanation:
- When i = 0, j = 1, k = 2, and l = 3, nums[i] < nums[k] < nums[j] < nums[l].
- When i = 0, j = 1, k = 2, and l = 4, nums[i] < nums[k] < nums[j] < nums[l].
There are no other quadruplets, so we return 2

Example 2:
Input: nums = [1,2,3,4]
Output: 0
Explanation: There exists only one quadruplet with i = 0, j = 1, k = 2, l = 3, but since nums[j] < nums[k], we return 0.

*/

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1);
        for(int i=0;i<n;i++){
            vector<int> prev(i+1);
            prev[0]=0;
            for(int j=0;j<i;j++){
                prev[j+1]=prev[j]+(nums[j]<nums[i]);
            }
        dp[nums[i]]=prev;
        }
        long long result=0;
        for(int i=1;i<n-1;i++){
            int counter=0, temp=0;
            for(int j=n-1;j>i;j--){
                if(nums[j]>nums[i]) counter++;
                else{
                    int curr=dp[nums[j]][i];
                    temp+=(curr)*counter;
                }
            }
        result+=temp;
        }
    return result;
    }
};
