/*
Given a matrix and a target, return the number of non-empty submatrices that sum to target.
A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

Example 1:
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Example 2:
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Example 3:
Input: matrix = [[904]], target = 0
Output: 0
*/


class Solution {
public:
    int helper(vector<int> &nums, int k){
        int sum=0, count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) count++;
            if(mp.find(sum-k)!=mp.end()) count+=mp[sum-k];
            mp[sum]++;
        }
    return count;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){
        int result=0, n=matrix.size();
        for(int i=0;i<n;i++){
            vector<int> curr(matrix[0].size(),0);
            for(int j=i;j<n;j++){
                for(int k=0;k<matrix[0].size();k++){
                    curr[k]+=matrix[j][k];
                }
                result+=helper(curr,target);
            }
        }
    return result;
    }
};
