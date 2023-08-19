/*
You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

Example 1:
Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.

Example 2:
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
*/

class Solution {
public:

    vector<int> LongestIncreasingSubsequence(vector<int>& arr, int n){
        vector<int> dp1(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] and dp1[i]<1+dp1[j]){
                    dp1[i]=1+dp1[j];
                }
            }
        }
    return dp1;
    }
    vector<int> LongestDecreasingSubsequence(vector<int> &arr, int n){
        vector<int> dp2(n,1);
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[j]<arr[i] and dp2[i]<1+dp2[j]){
                    dp2[i]=1+dp2[j];
                }
            }
        }
    return dp2;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size(), result=0;
        if(n<3) return 0;
        vector<int> LIS=LongestIncreasingSubsequence(nums,n);
        vector<int> LDS=LongestDecreasingSubsequence(nums,n);
        for(int i=n-2;i>=0;i--){
            if(LDS[i]>1 and LIS[i]>1){
                result=max(result,LDS[i]+LIS[i]-1);
            }
        }
    return n-result;
    }
};
