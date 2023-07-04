/*
Captain America is hiding from Thanos in a maze full of N rooms connected by M gates.
The maze is designed in such a way that each room leads to another room via gates. All connecting gates are unidirectional. Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
Help Thanos find the number of rooms in which Captain America can hide.

Example 1:
Input:
N = 5 and M = 5
V = [[1, 2], [2, 3], [3, 4], [4, 3], [5, 4]]
Output: 2
Explanation:

We can look closesly after forming graph
than captain america only can hide in a
room 3 and 4 because they are the only room
which have gates through them. So,
answer is 2.

Example 2:
Input:
N = 2, M = 1
V = [[1, 2]]
Output: 1

Your Task:
You don't need to read input or print anything. Your task is to complete the function captainAmerica() which takes the integer N, an integer M and 2-d array V as input parameters and returns the Total no of rooms.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N+M)
*/

class Solution{
public:
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        vector<int> adj[N+1];
        int indegree[N+1]={0};
        queue<int> q;
        for(int i=0;i<M;i++){
            adj[V[i][0]].push_back(V[i][1]);
            indegree[V[i][1]]++;
        }

        int terminalNodes=0;
        for(int i=1;i<=N and terminalNodes<2;i++){
            if(!adj[i].size()){
                terminalNodes++;
            }
            if(!indegree[i]) q.push(i);
        }
        if(terminalNodes) return terminalNodes==1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            N--;
            for(auto it : adj[curr]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    return N;
    }
};
