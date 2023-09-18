/*
You are given a 0-indexed 2D integer array nums representing the coordinates of the cars parking on a number line. For any index i, nums[i] = [starti, endi] where starti is the starting point of the ith car and endi is the ending point of the ith car.
Return the number of integer points on the line that are covered with any part of a car.

Example 1:
Input: nums = [[3,6],[1,5],[4,7]]
Output: 7
Explanation: All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.

Example 2:
Input: nums = [[1,3],[5,8]]
Output: 7
Explanation: Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.
*/

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums){
        if(nums.size()==0) return nums[0][1]-nums[0][0]+1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> temp=nums[0];
        int counter=0;
        for(auto num : nums){
            if(num[0]<=temp[1]){
                temp[1]=max(temp[1],num[1]);
            }else{
                result.push_back(temp);
                temp=num;
            }
        }
        result.push_back(temp);
        for(auto num : result){
            counter+=(num[1]-num[0]+1);
        }
    return counter;
    }
};
