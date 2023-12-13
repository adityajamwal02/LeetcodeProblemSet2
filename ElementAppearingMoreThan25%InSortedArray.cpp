/*
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

Example 1:
Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Example 2:
Input: arr = [1,1]
Output: 1
*/

class Solution {
public:
    // a quarter, half-way, third-quarter
    int findSpecialInteger(vector<int>& arr){
        int n=arr.size(), minReq=ceil(n/4);
        vector<int> nums={arr[n/4], arr[n/2], arr[3*n/4]};
        for(auto num : nums){
            int leftInd=lower_bound(arr.begin(),arr.end(),num)-arr.begin();
            int rightInd=upper_bound(arr.begin(),arr.end(),num)-arr.begin()-1;
            if(rightInd-leftInd+1>minReq) return num;
        }
    return -1;
    }
};
