/*
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

Example 1:
Input: N = 5, arr[] = {1, 101, 2, 3, 100}
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}

Example 2:
Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.
*/


    class Solution{
	public:
	int maxSumIS(int a[], int n)
	{
        vector<int> dp(n+1,INT_MIN);
        dp[0]=a[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    dp[i]=max(dp[i],a[i]+dp[j]);
                }
            dp[i]=max(dp[i],a[i]);
            }
        }
    return *max_element(dp.begin(),dp.end());
	}
};
