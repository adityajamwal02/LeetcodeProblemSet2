/*
Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Example 1:
Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.

Example 2:
Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

/// Recursion + memo

//User function template for C++
class Solution{
public:
	// calculate the maximum sum with out adjacent
	int helper(int i, int *arr, vector<int> &dp){
	    if(i==0) return arr[i];
	    if(i<0) return 0;
	    if(dp[i]!=-1) return dp[i];
	    int pick=arr[i]+helper(i-2,arr,dp);
	    int notPick=0+helper(i-1,arr,dp);
	return dp[i]=max(pick,notPick);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1,-1);
	return helper(n-1,arr,dp);
	}
};

/// Tabulation

class Solution{
public:
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1,0);
	    dp[0]=arr[0];
	    for(int i=1;i<n;i++){
	        int pick=arr[i]+dp[i-2];
	        int notPick=dp[i-1];
	        dp[i]=max(pick,notPick);
	    }
	return dp[n-1];
	}
};

/// Space Optimized
//User function template for C++
class Solution{
public:
	int findMaxSum(int *arr, int n) {
	    int prev2=0, prev=arr[0];
	    for(int i=1;i<n;i++){
	        int pick=arr[i]+prev2;
	        int notPick=prev;
	        int curr=max(pick,notPick);
	    prev2=prev;
	    prev=curr;
	    }
	return prev;
	}
};
