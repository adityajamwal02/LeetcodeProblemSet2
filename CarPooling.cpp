/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

Example 1:
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Example 2:
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
*/


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Breaking trips into 2 parts each : {from,enter,cap} and {to,leave,cap}
        // Sort on start points then {maintain 0/1 for leave/enter};
        vector<vector<int>> nums;
        for(int i=0;i<trips.size();i++){
            int cap=trips[i][0], low=trips[i][1], high=trips[i][2];
            nums.push_back({low,1,cap});
            nums.push_back({high,0,cap});
        }
        sort(nums.begin(),nums.end());
        int currCap=capacity;
        for(int i=0;i<nums.size();i++){
            int choice=nums[i][1], cap=nums[i][2];
            if(choice==1){
                currCap-=cap;
                if(currCap<0) return false;
            }else{
                currCap+=cap;
            }
        }
    return true;
    }
};
