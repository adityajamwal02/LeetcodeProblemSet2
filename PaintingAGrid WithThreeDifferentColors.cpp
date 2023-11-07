/*
You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 2:
Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.

Example 3:
Input: m = 5, n = 5
Output: 580986
*/

#define ll long long

class Solution {
    ll mod = 1e9+7;
public:
    void generate_mask(int m,int msk,vector<int> &masks,int &pre_msk,int pre_col){
        if(m==0){
            masks.push_back(msk);
            return;
        }
        for(int i=1;i<=3;i++)
            if(pre_col!=i and ((pre_msk>>((m-1)*2))&3)!=i)
                generate_mask(m-1,msk|(i<<(m-1)*2),masks,pre_msk,i);
    }

    int helper(int &m,int&n,int i,int msk,vector<vector<int>> &dp,unordered_map<int,vector<int>> &msk_map){
        if(i==n) return 1;
        if(dp[i][msk]!=-1) return dp[i][msk];
        if(msk_map.find(msk)==msk_map.end()) generate_mask(m,0,msk_map[msk],msk,0);
        ll ans = 0;
        for(auto cur_msk : msk_map[msk]){
            ans+=helper(m,n,i+1,cur_msk,dp,msk_map)*1LL;
            ans%=mod;
        }
    return dp[i][msk]=ans;
    }

    int colorTheGrid(int m, int n){
        // red = 01  |  green = 10  | blue = 11
        vector<vector<int>> dp(n,vector<int>(1<<(2*m),-1));
        unordered_map<int,vector<int>> msk_map;
    return (int)helper(m,n,0,0,dp,msk_map);
    }
};
