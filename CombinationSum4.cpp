/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Example 2:
Input: nums = [9], target = 3
Output: 0
*/

class Solution {
public:
    vector<int> dp;
    int help(vector<int> &nums, int target, int n){
        if(target==0)
            return 1;
        int ans=0;

        if(dp[target]!=-1)
            return dp[target];

        for(int i=0;i<n;i++)
        {
            if(nums[i]<=target)
            {
                ans+=help(nums, target-nums[i], n);
            }
        }
    return dp[target]=ans;
    }


    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(target+1, -1);
        return help(nums, target, n);
    }
};


// Tabulation


int findWays(vector<int> &num, int tar){
    int n=num.size();
    vector<int> dp(tar+1,0);
    dp[0]=1;
    for(int i=1;i<=tar;i++){
        for(int j=0;j<n;j++){
            if(num[j]<=i){
                dp[i]+=dp[i-num[j]];
            }
        }
    }
return dp[tar];
}
