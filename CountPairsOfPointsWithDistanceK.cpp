/*
You are given a 2D integer array coordinates and an integer k, where coordinates[i] = [xi, yi] are the coordinates of the ith point in a 2D plane.
We define the distance between two points (x1, y1) and (x2, y2) as (x1 XOR x2) + (y1 XOR y2) where XOR is the bitwise XOR operation.
Return the number of pairs (i, j) such that i < j and the distance between points i and j is equal to k.

Example 1:
Input: coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
Output: 2
Explanation: We can choose the following pairs:
- (0,1): Because we have (1 XOR 4) + (2 XOR 2) = 5.
- (2,3): Because we have (1 XOR 5) + (3 XOR 2) = 5.

Example 2:
Input: coordinates = [[1,3],[1,3],[1,3],[1,3],[1,3]], k = 0
Output: 10
Explanation: Any two chosen pairs will have a distance of 0. There are 10 ways to choose two pairs
*/

/// TLE

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k){
        int n=coordinates.size(), counter=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(((coordinates[i][0]^coordinates[j][0])+(coordinates[i][1]^coordinates[j][1]))==k){
                    counter++;
                }
            }
        }
    return counter;
    }
};


/// HashMap

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k){
        int n=coordinates.size(), counter=0;
        unordered_map<long long, int> mp;
        for(int i=0;i<n;i++){
            int x=coordinates[i][0], y=coordinates[i][1];
            for(int j=0;j<=k;j++){
                int left=j, right=k-j;
                long long target=(x^left)*10000000LL+(y^right);
            counter+=mp[target];
            }
        mp[x*10000000LL+y]++;
        }
    return counter;
    }
};
