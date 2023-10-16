/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.

Example 1:
Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:
Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points){
        int result=INT_MAX, n=points.size();
        unordered_map<int,unordered_set<int>> mp;
        for(auto point : points){
            mp[point[0]].insert(point[1]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0], y1=points[i][1];
                int x2=points[j][0], y2=points[j][1];
                if(x1!=x2 and y1!=y2){
                    if(mp[x1].find(y2)!=mp[x1].end() and mp[x2].find(y1)!=mp[x2].end()){
                        result=min(result,abs(x1-x2)*abs(y1-y2));
                    }
                }
            }
        }
    return (result==INT_MAX) ? 0 : result;
    }
};

