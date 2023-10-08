/*
Given two arrays nums1 and nums2.
Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

Example 1:
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

Example 2:
Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.

Example 3:
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.
*/

lass Solution {
public:
    int dp[501][501][2];
    int helper(int i, int j, int k, int n, int m, vector<int> &nums1, vector<int> &nums2){
        if(i==n or j==m){
            if(k==0) return INT_MIN;
        return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int result=INT_MIN;
        int op1=helper(i,j+1,k,n,m,nums1,nums2);
        int op2=helper(i+1,j,k,n,m,nums1,nums2);
        int op3=helper(i+1,j+1,1,n,m,nums1,nums2)+nums1[i]*nums2[j];
        result=max({result,op1,op2,op3});

    return dp[i][j][k]=result;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size(), m=nums2.size();
        memset(dp,-1,sizeof(dp));
    return helper(0,0,0,n,m,nums1,nums2);
    }
};
