/*
Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
The floor() function returns the integer part of the division.

Example 1:
Input: nums = [2,5,9]
Output: 10
Explanation:
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
We calculate the floor of the division for every pair of indices in the array then sum them up.

Example 2:
Input: nums = [7,7,7,7,7,7,7]
Output: 49
*/

class Solution {
public:
    long long mod=1e9+7;
    long long it=1e5;

    int sumOfFlooredPairs(vector<int>& nums){
        int n=nums.size();
        long long result=0;
        vector<long long> sieve(it+2,0), prefixSum(it+2,0);
        for(int i=0;i<n;i++) sieve[nums[i]]++;
        for(long long i=1;i<=it;i++) prefixSum[i]=prefixSum[i-1]+sieve[i];
        for(long long i=1;i<=it;i++){
            long long counter=1;
            for(long long j=i;j<=it;j+=i){
                long long start=j, end=j+i-1;
                end=min(it,end);
                long long sum=((prefixSum[end]-prefixSum[start-1])*counter)%mod;
                sum=(sum*sieve[i])%mod;
                result+=sum;
                result%=mod;
                counter++;
            }
        }
    return result;
    }
};
