/*
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.



Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4

*/

class Solution {
public:
    int mod=1e9+7;

    long long rev(int num){
        long long ans=0;
        while(num>0){
            ans=ans*10+num%10;
            num/=10;
        }
    return ans;
    }

    long long sum(int n){
        return (1LL*n*(n+1))/2-n;
    }

    int countNicePairs(vector<int>& nums){
        unordered_map<long long,int> mp;
        int n=nums.size(), counter=0;
        for(int i=0;i<n;i++){
            long long curr=rev(nums[i]);
            curr=nums[i]-curr;
            mp[curr]++;
        }
        for(auto it : mp){
            counter=(1LL*counter+(1LL*sum(it.second))%mod)%mod;
        }
    return counter;
    }
};
