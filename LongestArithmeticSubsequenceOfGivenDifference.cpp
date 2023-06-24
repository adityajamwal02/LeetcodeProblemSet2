/*
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
*/


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size(), result=0;
        unordered_map<int,int> dp;
        for(int i=0;i<n;i++){
            int temp=arr[i]-difference;
            int tempAns=0;
            if(dp.count(temp)){
                tempAns=dp[temp];
            }
            dp[arr[i]]=1+tempAns;
            result=max(result,dp[arr[i]]);
        }
    return result;
    }
};
