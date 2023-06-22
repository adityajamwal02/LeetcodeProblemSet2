/*
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.
Note: Answer can be very large, so, output answer modulo 109+7

Example 1:
Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5},
             {2, 3, 5}

Your Task:
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)
*/

/// Generating All Subsequences Matching condition and then returning size (TLE Recursion)

class Solution{

	public:

	vector<vector<int>> result;
    int mod=1e9+7;

    void solve(int i, int arr[], int n, vector<int> temp, int target){
        if(i==n){
            int sum=accumulate(temp.begin(),temp.end(),0);
            if(sum==target){
                result.push_back(temp);
            }
        return;
        }
        solve(i+1,arr,n,temp,target);
        int ele=arr[i];
        temp.push_back(ele);
        solve(i+1,arr,n,temp,target);
    }


	int perfectSum(int arr[], int n, int K)
	{
        vector<int> temp;
        solve(0,arr,n,temp,K);

    return result.size()%mod;
	}

};

/// Recursive Solution

	class Solution{
	public:
	int mod=1e9+7;

	int helper(int i, int j, int arr[], vector<vector<int>> &dp){
	    if(i==0){
	        if(j==0) return 1;
	    return 0;
	    }
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(arr[i-1]<=j) return dp[i][j]=(helper(i-1,j-arr[i-1],arr,dp)%mod + helper(i-1,j,arr,dp)%mod)%mod;
	    else return dp[i][j]=helper(i-1,j,arr,dp)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
    return helper(n,sum,arr,dp)%mod;
	}

};

/// DP Solution (Tabulation)

class Solution{
    int mod=1e9+7;
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<int> res(sum+1,0);
        res[0]=1;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=arr[i];j--){
                if(res[j-arr[i]]){
                    res[j]+=res[j-arr[i]];
                    res[j]=res[j]%mod;
                }
            }
        }
    return res[sum]%mod;
	}

};
