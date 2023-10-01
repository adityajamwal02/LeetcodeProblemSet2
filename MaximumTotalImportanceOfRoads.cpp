/*
You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.
You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.
Return the maximum total importance of all roads possible after assigning the values optimally.

Example 1:
Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 43
Explanation: The figure above shows the country and the assigned values of [2,4,5,3,1].
- The road (0,1) has an importance of 2 + 4 = 6.
- The road (1,2) has an importance of 4 + 5 = 9.
- The road (2,3) has an importance of 5 + 3 = 8.
- The road (0,2) has an importance of 2 + 5 = 7.
- The road (1,3) has an importance of 4 + 3 = 7.
- The road (2,4) has an importance of 5 + 1 = 6.
The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
It can be shown that we cannot obtain a greater total importance than 43.

Example 2:
Input: n = 5, roads = [[0,3],[2,4],[1,3]]
Output: 20
Explanation: The figure above shows the country and the assigned values of [4,3,2,5,1].
- The road (0,3) has an importance of 4 + 5 = 9.
- The road (2,4) has an importance of 2 + 1 = 3.
- The road (1,3) has an importance of 3 + 5 = 8.
The total importance of all roads is 9 + 3 + 8 = 20.
It can be shown that we cannot obtain a greater total importance than 20.
*/

/// Solution 1

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        long long result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        for(int i=0;i<n;i++){
            pq.push({indegree[i],i});
        }
        for(int i=n;i>=1;i--){
            mp.insert({pq.top().second,i});
            pq.pop();
        }
        for(auto road : roads){
            result+=(mp[road[0]]+mp[road[1]]);
        }
    return result;
    }
};

/// Solution 2

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long indegree[50001]={0}, result=0;
        for(auto road : roads){
            indegree[road[0]]++;
            indegree[road[1]]++;
        }
        sort(indegree,indegree+n);
        for(int i=0;i<n;i++){
            result+=(indegree[i]*(i+1));
        }

    return result;
    }
};
