/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/


class Solution {
public:

    int kDistinctSubarrays(vector<int> &arr, int n, int k){
        unordered_map<int,int> mp;
        int i=0, j=0, result=0;
        while(j<n){
            mp[arr[j]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0){
                        mp.erase(arr[i]);
                    }
                i++;
                }
            }
        result+=(j-i+1);
        j++;
        }
    return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
    return kDistinctSubarrays(nums,n,k)-kDistinctSubarrays(nums,n,k-1);
    }
};


/// More Optimized Code:

class Solution {
  public:
    int AtMostKDifferent(vector<int> &arr, int n, int k){
        vector<int> mp(n+1,0);
        int i=0, j=0, result=0, size=0;
        while(j<n){
            mp[arr[j]]++;
            if(mp[arr[j]]==1) size++;
            if(size>k){
                while(size>k){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0){
                        size--;
                    }
                i++;
                }
            }
        result+=(j-i+1);
        j++;
        }
    return result;
    }

    int subarrayCount(vector<int> &arr, int N, int K) {
        return AtMostKDifferent(arr,N,K)-AtMostKDifferent(arr,N,K-1);
    }
};

