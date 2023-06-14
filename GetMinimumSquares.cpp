/*
Given a number N. Find the minimum number of squares of any number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).

Example 1:
Input: N = 100
Output: 1
Explanation: 10 * 10 = 100

Example 2:
Input: N = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6

Your Task:
You don't need to read or print anyhting. Your task is to complete the function MinSquares() which takes N as input parameter and returns minimum number of squares needed to make N.

Expcted Time Complexity: O(N * sqrt(N) )
Expected Space Complexity: O(N)
*/

/// DP Solution

/// Tabulation

class Solution{
	public:
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,1000000);
	    dp[0]=0;
	    for(int i=1;i<=n;i++){
	        for(int j=0;j*j<=i;j++){
	            dp[i]=min(dp[i],1+dp[i-j*j]);
	        }
	    }
	return dp[n];
	}
};

/// Lagrange's Four-Square Theorem and Legendre's Three-Square Theorem

//User function Template for C++

class Solution{
	public:
	int isSquare(int n){
	    int sq=sqrt(n);
	    return sq*sq==n;
	}
	int MinSquares(int n)
	{
	    if(isSquare(n)) return 1;
	    int m=n;
	    while(m%4==0){
	        m/=4;
	    }
	    if(m%8==7){
	        return 4;
	    }
	    const int sq=sqrt(n);
	    for(int i=1;i<=sq;i++){
	        if(isSquare(n-i*i)) return 2;
	    }
	return 3;
	}
};
