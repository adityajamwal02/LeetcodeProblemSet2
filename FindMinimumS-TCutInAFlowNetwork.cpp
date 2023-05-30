/*
Given a weighted graph of N vertices numbered from 0 to N-1 in the form of adjacency matrix A[ ][ ] and two integers S
denoting the number of source vertex and T denoting the number of sink vertex.
The task is to find minimum capacity s-t cut of the given network. An s-t cut is a cut that requires the source node ‘S’ and the sink node ‘T’
to be in different subsets, and it consists of edges going from the source’s side to the sink’s side. The capacity of an s-t cut is defined
by the sum of the capacity of each edge in the cut-set. In other words, you have to find out all the edges which has to be removed to make
it impossible to reach the sink node from source node, and the edges you select should have a minimum sum of weights. You have to return all the edges
included in the minimum capacity s-t cut and if there are no edges in minimum capacity s-t cut, return "-1".

Example 1:
Input:
N = 2
A[][] = [[0, 3],
         [0, 0]]
S = 0
T = 1
Output:
0 1
Explanation: We have to remove the edge going
from 0th vertex to 1st vertex.

Example 2:
Input:
N = 5
A[][] = [[0, 0, 0, 0, 0],
         [0, 0, 2, 3, 0],
         [0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0],
         [0, 0, 0, 0, 0]]
S = 0
T = 4
Output:
-1
Explanation: There are no edges in
minimum capacity s-t cut.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimumCut() which takes the adjacency matrix A[ ][ ], source node number S, sink node number T and number of vertices N and returns a list of integers res[ ] where res[2*i-1] and res[2*i] denotes an edge in minimum capacity s-t cut where 1 ≤ i ≤ length(res)/2, if there are no edges in minimum capacity s-t cut, return only one integer "-1" in res[ ].

Expected Time Complexity: O(max_flow * N2)
Expected Auxiliary Space: O(N2)
*/

#include <bits/stdc++.h>
using namespace std;

struct comp{
bool operator()(pair<int,int> a,pair<int,int> b){
if(a.first == b.first)return a.second > b.second;
return a.first > b.first;
}
};

priority_queue<pair<int,int>,vector<pair<int,int>>, comp> ans;
int v,sss;bool flag=false;
void dfs(vector<vector<int>> &g,vector<bool> vis,stack<pair<int,int>> s,
int a,int t,int min){
pair<int,int> u;

if(a==t){
   //calc ans minus min from all traversed edge stores in stack
   while(!s.empty()){
       u=s.top();
       g[u.first][u.second]-=min;
       if(g[u.first][u.second]==0)ans.push(u);
       s.pop();
   }flag=true;return;
}

 vis[a] = true; //by default pq is descending
 priority_queue<pair<int,int>> index;//current flow in low resistance branch first
 //hypothesis 1 : max edge weight wali branch pehle explore krenge
    for (int i = 0; i < v; i++) {
        if (g[a][i] != 0 && (!vis[i])) {

            index.push({g[a][i],i});
        }
    }
   while(!index.empty()){
 if(flag)return;
     u=index.top();
      s.push({a,u.second});
      min=min<u.first?min:u.first;
      dfs(g,vis,s,u.second,t,min);
       index.pop();
   }


}


bool Dfs(vector<vector<int>> c,int s,int t,bool vis[]){
    vis[s]=true;
    if(s==t) return true;
    for(int i=0;i<c.size();i++){
        if(vis[i]==0&&c[s][i]>0){
           if(Dfs(c,i,t,vis))return true;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;int ss,tt;v=n;
        vector<vector<int>> c(n,vector<int>(n)),c1(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>c[i][j];
                c1[i][j]=c[i][j];
            }
        }
        cin>>ss>>tt;sss=ss;
     vector<bool> vis(n);stack<pair<int,int>> sta;
     dfs(c1,vis,sta,ss,tt,INT_MAX);
     bool visb[n];
     while (Dfs(c1,ss,tt, visb )) {flag=false;
     memset(visb,false,n);
      dfs(c1,vis,sta,ss,tt,INT_MAX);
     }
     pair<int,int> u ;
     while(!ans.empty()){
        u=ans.top();
       cout<<u.first<<" "<<u.second<<" ";
        ans.pop();
    } cout <<endl;
    }
	return 0;
}

