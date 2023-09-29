/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
Given the grid grid represented as a string array, return the number of regions.
Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:
Input: grid = [" /","/ "]
Output: 2

Example 2:
Input: grid = [" /","  "]
Output: 1

Example 3:
Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
*/

/// DSU Approach

class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
    return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid){
        int n=grid.size(), points=pow(n+1,2), result=1;
        DSU dsu(points);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0 or i==n or j==n){
                    dsu.parent[i*n+j]=0;
                }else{
                    dsu.parent[i*n+j]=i*n+j;
                }
            }
        }
        for(int i=0;i<n;i++){
            int index=0;
            string curr=grid[i];
            while(index<curr.size()){
                if(curr[index]=='/'){
                    int x=index, y=i;
                    int par1=dsu.findParent(x+1+y*n);
                    int par2=dsu.findParent(x+(y+1)*n);
                    if(par1==par2) result++;
                    else dsu.parent[par1]=par2;
                }else if(curr[index]=='\\'){
                    int x=index, y=i;
                    int par1=dsu.findParent(x+y*n);
                    int par2=dsu.findParent(x+1+(y+1)*n);
                    if(par1==par2) result++;
                    else dsu.parent[par1]=par2;
                }
            index++;
            }
        }
    return result;
    }
};
