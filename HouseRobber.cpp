/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

Example 1:
Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110

Example 2:
Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
Your Task:
Complete the functionFindMaxSum()which takes an array arr[] and n as input which returns the maximum money he can get following the rules

Expected Time Complexity:O(N).
Expected Space Complexity:O(N).
*/

/// Recursion

class Solution {
public:
    int helper(int i, vector<int> &nums){
        if(i==0) return nums[0];
        if(i<0) return 0;
        int pick=nums[i]+helper(i-2,nums);
        int notPick=helper(i-1,nums);
    return max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
    return helper(n-1,nums);
    }
};

/// Memoization

class Solution {
public:
    int helper(int i, vector<int> &nums, vector<int> &dp){
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+helper(i-2,nums,dp);
        int notPick=helper(i-1,nums,dp);
    return dp[i]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
    return helper(n-1,nums,dp);
    }
};

/// Tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
	    dp[0]=nums[0];
	    for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
	        int notPick=dp[i-1];
	        dp[i]=max(pick,notPick);
	    }
	return dp[n-1];
	}
};

/// Space Optimized

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0, prev=nums[0];
	    for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
	        int notPick=prev;
	        int curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
	    }
	return prev;
	}
};


