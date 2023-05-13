/*
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'
Return true if you can reach index s.length - 1 in s, or false otherwise

Example 1:
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3.
In the second step, move from index 3 to index 5.

Example 2:
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
*/

/// Queue based

bool canReach(string s, int mini, int maxi) {
        if(s[s.size()-1] != '0')
            return false;
        int curmaxi=0,si=s.size()-1;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            if(top == s.size()-1)
                return true;
            for(int i = max(top+mini,curmaxi);i <= min(si,top+maxi);i++)
            {
                if(s[i] == '0')
                    q.push(i);
            }
            curmaxi = top+maxi+1;
        }
        return false;
}


/// DP + Suffix Sum

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.front()=='1' or s.back()=='1') return false;
        int n=s.size();
        vector<bool> dp(n);
        vector<int> suffix(n);
        suffix[n-1]=1;
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            int l=i+minJump, r=min(i+maxJump,n-1);
            if(s[i]=='1' or l>n-1){
                dp[i]= false;
                suffix[i]=suffix[i+1];
                continue;
            }else{
                int count;
                if(r==n-1){
                    count=suffix[l];
                }else{
                    count=suffix[l]-suffix[r+1];
                }

                if(count>0){
                    dp[i]=true;
                    suffix[i]=suffix[i+1]+1;
                }else{
                    dp[i]=false;
                    suffix[i]=suffix[i+1];
                }
            }
        }
    return dp[0];
    }
};
