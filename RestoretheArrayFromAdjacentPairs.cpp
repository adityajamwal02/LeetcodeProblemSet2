/*
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.
You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.
It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.
Return the original array nums. If there are multiple solutions, return any of them.

Example 1:
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.

Example 2:
Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.

Example 3:
Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
*/

class Solution {
public:
    void dfs(int node, map<int,vector<int>> &adj, map<int,bool> &vis, vector<int> &result){
        vis[node]=true;
        result.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,result);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs){
        vector<int> result;
        map<int,vector<int>> adj;
        map<int,bool> vis;
        int endPoint=0;
        for(auto edge : adjacentPairs){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(auto it : adj){
            if(it.second.size()==1) endPoint=it.first;
        }
        dfs(endPoint,adj,vis,result);

    return result;
    }
};
