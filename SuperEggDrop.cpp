/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input: k = 1, n = 2
Output: 2
Explanation:
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:
Input: k = 2, n = 6
Output: 3

Example 3:
Input: k = 3, n = 14
Output: 4
*/

/// DP + Binary Search


class Solution {
public:
    // k eggs : n floors
    int helper(int k, int n, vector<vector<int>> &dp){
        if(n==0 or n==1) return n;
        if(k==1) return n;
        if(dp[n][k]!=-1) return dp[n][k];
        int low=1, high=n, result=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int lower=0, upper=0;
            if(dp[mid-1][k-1]!=-1){
                lower=dp[mid-1][k-1];
            }else{
                lower=helper(k-1,mid-1,dp);
                dp[mid-1][k-1]=lower;
            }
            if(dp[n-mid][k]!=-1){
                upper=dp[n-mid][k];
            }else{
                upper=helper(k,n-mid,dp);
                dp[n-mid][k]=upper;
            }
            int temp=1+max(lower,upper);
            dp[n][k]=temp;
            result=min(result,temp);
        if(lower<upper) low=mid+1;
        else if(lower>upper) high=mid-1;
        else break;
        }
    return dp[n][k]=result;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return helper(k,n,dp);
    }
};
