/// Sorting the chocolate : Coding ninjas

#include<bits/stdc++.h>

vector<int> sortedMatrix(vector<vector<int>> &mat, int n)
{
    vector<int> result;
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({{mat[i][0], i},0});
    }
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        result.push_back(it.first.first);
        int currRow=it.first.second;
        int currCol=it.second;
        if(it.second<n-1){
          pq.push({{mat[currRow][currCol + 1], currRow}, currCol + 1});
        }
    }
return result;
}
