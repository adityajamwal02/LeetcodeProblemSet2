/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.
Note: if no segment can be cut then return 0.

Example 1:
Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.

Example 2:
Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Your Task:
You only need to complete the function maximizeTheCuts() that takes n, x, y, z as parameters and returns max number cuts.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)
*/

/// Recursion + Memoization

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int helper(int n, int x, int y, int z, vector<int> &dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int take1=INT_MIN, take2=INT_MIN, take3=INT_MIN;
        if(n>=x) take1=helper(n-x,x,y,z,dp);
        if(n>=y) take2=helper(n-y,x,y,z,dp);
        if(n>=z) take3=helper(n-z,x,y,z,dp);
        dp[n]=1+max({take1,take2,take3});
    return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int result=helper(n,x,y,z,dp);
    return result<0 ? 0 : result;
    }
};

/// Tabulation

class Solution
{
    public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
            if (i - x >= 0)
                take1 = dp[i - x];
            if (i - y >= 0)
                take2 = dp[i - y];
            if (i - z >= 0)
                take3 = dp[i - z];
            dp[i] = 1 + max({ take1, take2, take3 });
        }
        return dp[n] < 0 ? 0 : dp[n];
    }
};

