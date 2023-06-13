/*
You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).
The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.
There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.
Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

Example 1:
Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
Output: 5
Explanation: The optimal path from (1,1) to (4,5) is the following:
- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.

Example 2:
Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
Output: 7
Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.
*/

/// BFS (Queue Based Solution)

class Solution {
public:
    int distance(int x1, int y1, int x2, int y2){
        return abs(x1-x2)+abs(y1-y2);
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        vector<vector<int>> chosen;
        chosen.push_back({start[0],start[1],start[0],start[1],0});
        for(auto it : specialRoads){
            if(distance(it[0],it[1],it[2],it[3])>it[4]){
                chosen.push_back(it);
            }
        }
        vector<int> dist(chosen.size(),INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0]=0;
        while(!q.empty()){
            auto [it,weight]=q.front();
            q.pop();
            int x=chosen[it][2], y=chosen[it][3];
            for(int j=0;j<chosen.size();j++){
                vector<int> &road=chosen[j];
                int start_x=road[0], start_y=road[1], dest_x=road[2], dest_y=road[3], cost=road[4];
                int currDist=distance(x,y,start_x, start_y) + weight + cost;
                if(currDist<dist[j]){
                    dist[j]=currDist;
                    q.push({j,currDist});
                }
            }
        }
        int result=INT_MAX;
        for(int i=0;i<chosen.size();i++){
            vector<int> &road=chosen[i];
            result=min(result,dist[i]+distance(road[2],road[3],target[0],target[1]));
        }
    return result;
    }
};


