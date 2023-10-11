/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.
Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

Example 1:
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Example 2:
Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
*/

class Solution {
public:
    int binarySearch(vector<int> &nums, int val){
        int low=0, high=nums.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(val<nums[mid]) high=mid;
            else low=mid+1;
        }
    return low;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people){
        int n=people.size();
        vector<int> start, end, result(n);
        for(int i=0;i<flowers.size();i++){
            start.push_back(flowers[i][0]);
        }
        for(int i=0;i<flowers.size();i++){
            end.push_back(flowers[i][1]+1);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(int i=0;i<people.size();i++){
            int bloomStart=binarySearch(start,people[i]);
            int bloomEnd=binarySearch(end,people[i]);
            result[i]=bloomStart-bloomEnd;
        }
    return result;
    }
};
