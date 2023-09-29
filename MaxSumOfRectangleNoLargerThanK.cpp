/*
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
It is guaranteed that there will be a rectangle with a sum no larger than k.

Example 1:
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

Example 2:
Input: matrix = [[2,2,-1]], k = 3
Output: 3
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(), m=matrix[0].size(), result=INT_MIN;
        vector<vector<int>> prefixSum(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefixSum[i][j]=matrix[i-1][j-1]+prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                set<int> st;
                st.insert(0);
                for(int c=1;c<=m;c++){
                    int area=prefixSum[j][c]-prefixSum[i-1][c];
                    auto it=st.lower_bound(area-k);
                    if(it!=st.end()) result=max(result,area-*it);
                st.insert(area);
                }
            }
        }
    return result;
    }
};
