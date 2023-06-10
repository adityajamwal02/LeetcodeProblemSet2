/*
You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.
Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.
It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

Example 1:
Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.

Example 2:
Input: points = [[0,0],[3,0],[9,2]], k = 3
Output: 3
Explanation: Only the first two points have an absolute difference of 3 or less in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
*/


class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        pq.push({points[0][1]-points[0][0],points[0][0]});
        int result=INT_MIN, sum=0;
        for(int i=1;i<points.size();i++){
            sum=points[i][0]+points[i][1];
            while(!pq.empty() and points[i][0]-pq.top()[1]>k){
                pq.pop();
            }
            if(!pq.empty()){
                result=max(result,sum+pq.top()[0]);
            }
        pq.push({points[i][1]-points[i][0],points[i][0]});
        }
    return result;
    }
};
