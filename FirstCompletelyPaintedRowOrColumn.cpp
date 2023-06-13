/*
You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.



Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
*/

/// 2 Map based approach

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> mpr, mpc, mprc, mpcc;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mpr[mat[i][j]]=i;
                mpc[mat[i][j]]=j;
            }
        }
        for(int i=0;i<arr.size();i++){
            int element=arr[i];
            mprc[mpr[element]]++;
            mpcc[mpc[element]]++;
            if(mprc[mpr[element]]==mat[0].size() or mpcc[mpc[element]]==mat.size()){
                return i;
            }
        }
    return -1;
    }
};


/// Optimized code (1 map)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int mini=INT_MAX, maxi=INT_MIN;
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            maxi=INT_MIN;
            for(int j=0;j<m;j++){
                int value=mp[mat[i][j]];
                maxi=max(maxi,value);
            }
            mini=min(mini,maxi);
        }
        for(int j=0;j<m;j++){
            maxi=INT_MIN;
            for(int i=0;i<n;i++){
                int value=mp[mat[i][j]];
                maxi=max(maxi,value);
            }
            mini=min(mini,maxi);
        }
        return mini;
    }
};
