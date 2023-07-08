/*
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1], k = 1
Output: 1

Example 2:
Input: nums = [1,2], k = 4
Output: -1

Example 3:
Input: nums = [2,-1,2], k = 3
Output: 3
*/


/// PQ Solution + Sliding Window

class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k){
        priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        long long currSum=0, result=INT_MAX;
        for(long long i=0;i<nums.size();i++){
            currSum+=nums[i];
            if(currSum>=k){
                result=min(result,i+1);
            }
            while(!pq.empty() and (currSum-pq.top().first)>=k){
                result=min(result,i-pq.top().second);
                pq.pop();
            }
            pq.push({currSum,i});
        }
    return result==INT_MAX ? -1 : result;
    }
};

/// Deque Solution + Sliding Window

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long n=nums.size(), result=INT_MAX, currSum=0;
        deque<pair<long,long>> dq;
        for(long long i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum>=k) result=min(result,i+1);
            pair<long long, long long> curr={INT_MIN,INT_MIN};
            while(!dq.empty() and (currSum-dq.front().second)>=k){
                result=min(result,i-dq.front().first);
                dq.pop_front();
            }
            while(!dq.empty() and dq.back().second >= currSum){
                dq.pop_back();
            }
            dq.push_back({i,currSum});
        }
    return result==INT_MAX ? -1 : result;
    }
};
