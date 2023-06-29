/*
You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:

For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.



Example 1:

Input: nums = [2,3,6]
Output: 2
Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
Example 2:

Input: nums = [1,4,3]
Output: 2
Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
*/


/// DP + Bitmasking : (Idea similar to count number of hamiltonian paths in a graph)

class Solution {
public:
    int mod=1e9+7;

    int helper(vector<int> &nums, int prev, int curr, int permutation, vector<vector<int>> &dp){
        if(curr==nums.size()) return 1;
        if(dp[prev+1][permutation]!=-1) return dp[prev+1][permutation];
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if((1<<i)&permutation) // Check for set bits (if set then continue)
                continue;
            if(prev==-1 or nums[prev]%nums[i]==0 or nums[i]%nums[prev]==0){ // condition check
                ans+=helper(nums,i,curr+1,permutation|(1<<i),dp);
                ans=ans%mod;
            }
        }
    return dp[prev+1][permutation]=ans;
    }

    int specialPerm(vector<int>& nums) {
        int n=nums.size(), prevIndex=-1, currIndex=0;
        int permutation=0;       // Bit representation : if ith bit is 0 : not Taken else taken
        if(n==1) return 1;
        vector<vector<int>> dp(15, vector<int> ((1<<14)+5, -1));  // memoization purpose dp

    return helper(nums,prevIndex,currIndex,permutation,dp);
    }
};

/// Solution

/*
So, we will iterate i=0 to i=nums.size() through each index of num and will check if that index can be used or not?
So for this we'll have condition nums[prev]%nums[i]==0||nums[i]%nums[prev]==0. Also ifprev==-1 which means currently no index has been added. So we will add the ith index.
Now, this ith index has been taken in permutation. Now we'll move forward for the next index recursively.
So we will get the answer for next index as follows:
solve(nums,i,ind+1,dp,permutation|(1<<i)) here we have new prev that is i new ind that is ind+1 b'coz we moved for the next index of our permutation, also the permutation will be changed to permutation|(i<<j) this will show that the ith index has been added to our permutation.
Now we'll add the recursive solution of solve(nums,i,ind+1,dp,permutation|(1<<i)) in a predefined variable int total=0; and after iterating through all index of nums we will return that total as our final ans. Also for memoization we will store this value in dp[prev+1][permutation]
Some cases we need to avoid that if the ith index is already in permutation, we will ignore it.
Taking base cases: If the ind reaches to the last ie. ind==nums.size() then we will return 1; which means we have a one permutation with us.
To avoid repitation if the value of dp[prev+1][permutation]!=-1 which means we have already computed the value, return dp[prev+1][permutation]
*/

/// TC -> 2^n * n^2
/// SC -> 2^n * n

