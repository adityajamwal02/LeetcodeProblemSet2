/*
Given an array A of size N. Find the maximum subset-sum of elements that you can make from the given array such that for every two consecutive elements in the array, at least one of the elements is present in our subset.

Example 1:
Input:
N = 4
A[] = {1, -1, 3, 4}
Output: 8
Explanation:
We can choose 0th,2nd & 3rd index(0 based
Index),so that it can satisfy the
condition & can make maximum sum 8.

Example 2:
Input:
N = 3
A[] =  {0, 2, 0};
Output: 2
Explanation:
We can choose 1st index. Here the
maximum possible sum is 2.
Your task:

You don't have to read input or print anything. Your task is to complete the function findMaxSubsetSum() which takes the array A and its size N as input and returns the Maximum possible subset-sum.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<pair<long long, long long>> result(N+1);
        for(int i=1;i<=N;i++){
            result[i]={max(result[i-1].first, result[i-1].second)+A[i-1] , result[i-1].first};
        }
    return max(result.back().first , result.back().second);
    }
};
