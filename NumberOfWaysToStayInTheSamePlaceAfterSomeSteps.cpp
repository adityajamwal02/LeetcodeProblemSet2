/*
You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).
Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

Example 1:
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Example 2:
Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Example 3:
Input: steps = 4, arrLen = 2
Output: 8
*/

/// Memoization 1

class Solution {
public:
    int mod=1e9+7, arrLen;
    int helper(int i, int remain, vector<vector<int>> &dp){
        if(remain==0){
            if(i==0) return 1;
        return 0;
        }
        if(dp[i][remain]!=-1) return dp[i][remain];
        int res=helper(i,remain-1,dp);
        if(i>0){
            res=(res+helper(i-1,remain-1,dp))%mod;
        }
        if(i<arrLen-1){
            res=(res+helper(i+1,remain-1,dp))%mod;
        }
    return dp[i][remain]=res;
    }

    int numWays(int steps, int arrLen){
        int n=min(steps,arrLen);
        this->arrLen=arrLen;
        vector<vector<int>> dp(n+1,vector<int>(steps+1,-1));
    return helper(0,steps,dp);
    }
};


/// Memoization 2

class Solution {
public:
    int mod=1e9+7;
    long long helper(int i, int steps, int arrLen, vector<vector<long long>> &dp){
        if(i>=arrLen or steps<0 or i<0) return 0;
        if(steps==0 and i==0) return 1;
        if(dp[i][steps]!=-1) return dp[i][steps];
        long long right=helper(i+1,steps-1,arrLen,dp);
        long long left=helper(i-1,steps-1,arrLen,dp);
        long long stay=helper(i,steps-1,arrLen,dp);

    return dp[i][steps]=(right+left+stay)%mod;
    }

    int numWays(int steps, int arrLen){
        int n=min(steps,arrLen);
        vector<vector<long long>> dp(n+1,vector<long long>(steps+1,-1));
    return helper(0,steps,arrLen,dp);
    }
};

/// Tabulation

int numWays(int steps, int arrLen){
    int n=min(steps,arrLen);
    vector<vector<long long>> dp(n+1,vector<long long>(steps+1,0));
    dp[0][0]=1;
    for(int i=1;i<=steps;i++){
        for(int index=n-1;index>=0;index--){
            long long right=0, left=0, stay=0;
            if(index<n-1) right=dp[index+1][i-1];
            stay=dp[index][i-1];
            if(index>0) left=dp[index-1][i-1];
        dp[index][i]=(left+right+stay)%mod;
        }
    }
return dp[0][steps];
}
