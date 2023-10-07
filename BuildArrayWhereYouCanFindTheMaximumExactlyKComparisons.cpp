/*
You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:
You should build the array arr which has the following properties:
arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

Example 1:
Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

Example 2:
Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.

Example 3:
Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
*/

class Solution {
public:
    int mod=1e9+7;
    int dp[51][101][51];

    int helper(int i, int val, int index, int n, int m, int k){
        if(i==n) return index+1==k;
        if(dp[i][val][index]!=-1) return dp[i][val][index];
        int result=0;
        for(int j=1;j<=m;j++){
            if(i==0) result=(result+helper(i+1,j,0,n,m,k))%mod;
            else{
                if(j>val){
                    result=(result+helper(i+1,j,index+1,n,m,k))%mod;
                }else{
                    result=(result+helper(i+1,val,index,n,m,k))%mod;
                }
            }
        }
    return dp[i][val][index]=result;
    }

    int numOfArrays(int n, int m, int k){
        if(k>n) return 0;
        memset(dp,-1,sizeof(dp));
    return helper(0,0,0,n,m,k);
    }
};

