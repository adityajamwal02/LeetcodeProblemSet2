/*
You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

Example 1:
Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

Example 2:
Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

Example 3:
Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.

*/


/// Recursive Solution

class Solution {
public:
    int helper(int i, int n, int s1, int s2, vector<int> &rods){
        if(i==n){
            if(s1==s2) return s1;
            return 0;
        }
        int result=0;
        int op1=helper(i+1,n,s1,s2,rods);
        int op2=helper(i+1,n,s1+rods[i],s2,rods);
        int op3=helper(i+1,n,s1,s2+rods[i],rods);
    return result=max({op1,op2,op3});
    }
    int tallestBillboard(vector<int>& rods){
        int n=rods.size();
        int s1=0, s2=0;
    return helper(0,n,s1,s2,rods);
    }
};


/// Memoized by state depreciation .. turning 3D into 2D (states merge)

const int offset=5000;

class Solution {

    int ans, n;
    vector<int> rods;
    int dp[21][2*offset+1];

public:
    int helper(int i, int diff){
        if(i==n){
            if(diff==0) return 0;
            return INT_MIN  ;
        }
        if(dp[i][diff+offset]!=-1) return dp[i][diff+offset];

        int op1=helper(i+1,diff);
        int op2=rods[i]+helper(i+1,diff+rods[i]);
        int op3=helper(i+1,diff-rods[i]);

    return dp[i][diff+offset]=max({op1,op2,op3});
    }

    int tallestBillboard(vector<int>& rods){
        this->rods=rods;
        n=rods.size();
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,0);         // i,diff(s1-s2)

    return (ans<0) ? 0 : ans;
    }
};
