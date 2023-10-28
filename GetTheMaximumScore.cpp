/*
A valid path is defined as follows:
Choose array nums1 or nums2 to traverse (from index-0).
Traverse the current array from left to right.
If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
The score is defined as the sum of unique values in a valid path.
Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 109 + 7.

Example 1:
Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green [2,4,6,8,10].

Example 2:
Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].

Example 3:
Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
Output: 40
Explanation: There are no common elements between nums1 and nums2.
Maximum sum is obtained with the path [6,7,8,9,10].
*/

/// DP : 2 memoized arrays: from (n-1, m-1) -> (0,0) take max(dp1[0],dp2[0])

class Solution {
public:
    long long mod=1e9+7;

    int maxSum(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size(), m=nums2.size(), i=n-1, j=m-1;
        long long dp1[n+1], dp2[m+1];
        dp1[n]=dp2[m]=0;
        while(i>=0 and j>=0){
            if(nums1[i]>nums2[j]){
                dp1[i--]=dp1[i+1]+nums1[i];
            }else if(nums1[i]<nums2[j]){
                dp2[j--]=dp2[j+1]+nums2[j];
            }else{
                dp1[i--]=dp2[j--]=nums1[i]+max(dp1[i+1],dp2[j+1]);
            }
        }
        while(i>=0) dp1[i--]=dp1[i+1]+nums1[i];
        while(j>=0) dp2[j--]=dp2[j+1]+nums2[j];

    return max(dp1[0],dp2[0])%mod;
    }
};


