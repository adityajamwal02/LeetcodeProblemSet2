/*
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
In the ith operation (1-indexed), you will:
Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.
The function gcd(x, y) is the greatest common divisor of x and y.

Example 1:
Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

Example 2:
Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

Example 3:
Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
*/

/// Recursive Solution (TLE)

class Solution {
public:
    int helper(int operation, int n, vector<int> &nums){
        if(operation==n) return 0;
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                for(int j=i+1;j<n;j++){
                    if(nums[j]!=0){                 /// Checking for i,j for value of 0 else to avoid it, later converting it back.
                        int a=nums[i], b=nums[j];
                        int temp=__gcd(a,b);
                        nums[i]=nums[j]=0;          /// Update the array so that current recursive function doesnt take same i,j
                        result=max(result, helper(operation+1,n,nums)+(operation+1)*temp);  /// Taking max into result and returning it
                        nums[i]=a; nums[j]=b;       /// Backtracking part to get back the elements after one check of max result;
                    }
                }
            }
        }
    return result;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
    return helper(0,n,nums);
    }
};

/// Memoization

class Solution {
public:
    int helper(int operation, int n, vector<int> &nums, int mask, vector<int> &dp){
        if(operation==n) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                for(int j=i+1;j<n;j++){
                    if(nums[j]!=0){                 /// Checking for i,j for value of 0 else to avoid it, later converting it back.
                        int a=nums[i], b=nums[j];
                        int temp=__gcd(a,b);
                        nums[i]=nums[j]=0;          /// Update the array so that current recursive function doesnt take same i,j
                        mask=mask|(1<<i)|(1<<j);
                        result=max(result, helper(operation+1,n,nums,mask,dp)+(operation+1)*temp);  /// Taking max into result and returning it
                        nums[i]=a; nums[j]=b;       /// Backtracking part to get back the elements after one check of max result;
                        mask=mask^(1<<i)^(1<<j);
                    }
                }
            }
        }
    return dp[mask]=result;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(1<<15,-1);
    return helper(0,n,nums,0,dp);
    }
};
