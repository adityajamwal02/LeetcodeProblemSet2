/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. You can select pairs in any order.

Example 1:
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

Example 2:
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
*/


class Solution {
public:
    vector<int> start,dp;
    int solve(vector<vector<int>> &pairs, int index){
        if(index==pairs.size()) return 0;
        else if(dp[index]!=-1) return dp[index];
        else{
            int ans1=solve(pairs,index+1);
            int upperBound=upper_bound(start.begin(),start.end(),pairs[index][1])-start.begin();
            int ans2=1+solve(pairs,upperBound);
        return dp[index]=max(ans1,ans2);
        }
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<n;i++){
            start.push_back(pairs[i][0]);
            dp.push_back(-1);
        }
    return solve(pairs,0);
    }
};
