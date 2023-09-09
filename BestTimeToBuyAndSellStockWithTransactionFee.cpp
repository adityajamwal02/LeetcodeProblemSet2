/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
*/


/// Recursive Solution

class Solution {
public:
    int helper(int i, int tran, int fee, vector<int> &prices, int n){
        if(i==n) return 0;
        int profit;
        if(tran%2==0){
            int buy=-prices[i]+helper(i+1,tran+1,fee,prices,n);
            int notbuy=helper(i+1,tran,fee,prices,n);
            profit=max(buy,notbuy);
        }else{
            int sell=prices[i]-fee+helper(i+1,tran+1,fee,prices,n);
            int notsell=helper(i+1,tran,fee,prices,n);
            profit=max(sell,notsell);
        }
    return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        return helper(0,0,fee,prices,n);
    }
};


/// Memoization

class Solution {
public:
    int helper(int i, int tran, int fee, vector<int> &prices, int n,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][tran]!=-1){
            return dp[i][tran];
        }
        int profit;
        if(tran){
            int buy=-prices[i]+helper(i+1,0,fee,prices,n,dp);
            int notbuy=helper(i+1,1,fee,prices,n,dp);
            profit=max(buy,notbuy);
        }else{
            int sell=prices[i]-fee+helper(i+1,1,fee,prices,n,dp);
            int notsell=helper(i+1,0,fee,prices,n,dp);
            profit=max(sell,notsell);
        }
    return dp[i][tran]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return helper(0,1,fee,prices,n,dp);
    }
};

/// Tabulation

class Solution {
public:
	int maxProfit(vector<int>& p, int fee) {
		int n=p.size();
		vector<vector<int>> dp(n+1,vector<int>(2,0));
		for(int i=n-1;i>=0;i--){
			for(int b=0;b<=1;b++){
				int profit;
				if(b){
					int buy= -p[i]+dp[i+1][0];
					int notbuy= dp[i+1][1];
					profit=max(buy,notbuy);
				}
				else{
					int sell= p[i]-fee+dp[i+1][1];
					int notsell= dp[i+1][0];
					profit=max(sell,notsell);
				}
				dp[i][b]=profit;
			}
		}
		return dp[0][1];
	}
};

/// Space Optimized

int maximumProfit(vector<int> &prices, int n, int fee){
	vector<int> curr(n+1,0), next(n+1,0);
	int profit=0;
	for(int i=n-1;i>=0;i--){
		curr[0]=max(next[0],-prices[i]+next[1]);	// buy

		curr[1]=max(next[1],+prices[i]-fee+next[0]);	// sell

	next=curr;
	}

return next[0];
}
