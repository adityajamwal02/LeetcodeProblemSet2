/*
Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

Example 1:
Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]

Example 2:
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
*/


class Solution {
public:
    // up (i-1,j+1)
    vector<int> findDiagonalOrder(vector<vector<int>>& nums){
        int n=nums.size(), counter=0;
        vector<int> result;
        map<int,vector<int>> mp;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                int level=i+j;
                mp[level].push_back(nums[i][j]);
            }
        }
        for(auto it : mp){
            vector<int> temp=it.second;
            for(int num : temp){
                result.push_back(num);
            }
        }
    return result;
    }
};
