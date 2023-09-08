/*
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

Example 1:
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.

Example 2:
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10

*/

class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,-1,0,1};

    int trapRainWater(vector<vector<int>>& heightMap){
        int n=heightMap.size(), m=heightMap[0].size(), result=0;
        // Walls (Boundary, minheap)
        vector<int> vis(n*m,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<m;i++){
            vis[i]=1;
            vis[(n-1)*m+i]=1;
            pq.push({heightMap[0][i],i});
            pq.push({heightMap[n-1][i],(n-1)*m+i});
        }
        for(int i=0;i<n;i++){
            vis[i*m]=1;
            vis[(i+1)*m-1]=1;
            pq.push({heightMap[i][0],i*m});
            pq.push({heightMap[i][m-1],(i+1)*m-1});
        }
        while(!pq.empty()){
            int wallHeight=pq.top().first;
            int node=pq.top().second, row=node/m, col=node%m;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                int newNode=nrow*m+ncol;
                if(nrow>=0 and ncol>0 and nrow<n and ncol<m and vis[newNode]==0){
                    vis[newNode]=1;
                    if(wallHeight-heightMap[nrow][ncol]>0){
                        result+=wallHeight-heightMap[nrow][ncol];
                        pq.push({wallHeight,newNode});
                    }else{
                        pq.push({heightMap[nrow][ncol],newNode});
                    }
                }
            }
        }
    return result;
    }
};
