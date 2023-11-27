/*
You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.
You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.
For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.
Return an array answer, where answer[j] is the answer to the jth query.

Example 1:
Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.

Example 2:
Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
Output: [2,3,2,4]
Explanation: The points and circles are shown above.
queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.
*/

/// Brute

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries){
        vector<int> result;
        for(auto q : queries){
            int x0=q[0], y0=q[1], r0=q[2], counter=0;
            for(auto p : points){
                int x1=p[0], y1=p[1];
                if((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1) <= r0*r0){
                    counter++;
                }
            }
        result.push_back(counter);
        }
    return result;
    }
};

/// Sort + Binary Search

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        sort(points.begin(), points.end());
        for(int i=0; i<queries.size(); i++){
            auto& q = queries[i];
            int x = q[0], y = q[1], r = q[2];
            auto it = lower_bound(points.begin(), points.end(), vector<int>{x-r,0});
            for(; it != points.end() and (*it)[0] <= x+r; it++){
                int d2 = ((*it)[0]-x)*((*it)[0]-x) + ((*it)[1]-y)*((*it)[1]-y);
                if(d2 <= r*r) ans[i]++;
            }
        }
        return ans;
    }
};
