/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
Return a boolean array answer, where answer[j] is the answer to the jth query.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.

Example 2:
Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.

Example 3:
Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
*/

/// Flyod Warshall Transitive Dependency

class Solution {
public:
    void addTransitiveDependency(vector<vector<int>> &adj, int n){
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j or adj[i][j]==1) continue;
                    if(adj[i][k] and adj[k][j]){
                        adj[i][j]=1;
                    }
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries){
        int n=numCourses;
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(auto pre : prerequisites){
            adj[pre[0]][pre[1]]=1;
        }
        addTransitiveDependency(adj,numCourses);
        vector<bool> result;
        for(auto q : queries){
            result.push_back(adj[q[0]][q[1]]);
        }
    return result;
    }
};


/// Topological Sort

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);

        for(auto edge: prerequisites){
            indegree[edge[1]]+=1;

            graph[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        vector<vector<bool>> table(n, vector<bool>(n, false));

        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }


        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto itr: graph[curr]){
                table[curr][itr]=true;

                indegree[itr]-=1;
                if(indegree[itr]==0)
                    q.push(itr);

                for(int i=0;i<n;i++){
                    if(table[i][curr])
                        table[i][itr]=true;
                }
            }
        }

        vector<bool> result;

        for(auto query:queries){
            result.push_back(table[query[0]][query[1]]);
        }

        return result;
    }
};
