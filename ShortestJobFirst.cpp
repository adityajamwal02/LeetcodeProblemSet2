/// Shortest Job First : Program for scheduling algorithms  Greedy Approach

#include<bits/stdc++.h>
using namespace std;

float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime){
    vector<pair<int,int>> nums;
    for(int i=0;i<n;i++){
      nums.push_back({arrivalTime[i], burstTime[i]});
    }
    sort(nums.begin(),nums.end(),greater<pair<int,int>>());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    auto it=nums.back();
    nums.pop_back();
    pq.push({it.second,it.first});
    int time=it.first;
    float waiting=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        waiting+=time-it.second;
        time+=it.first;
        auto top=nums.begin();
        while(top!=nums.end()){
            if((*top).first<=time){
                pq.push({(*top).second,(*top).first});
                nums.erase(top);
            }else{
                top++;
            }
        }
    }
return (float)(waiting/n);
}

int main(){
    int n;
    cin>>n;
    vector<int> arrivalTime(n), burstTime(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arrivalTime[i]=x;
        burstTime[i]=y;
    }
    float result=sjf(n,arrivalTime,burstTime);
    cout<<result<<endl;

    return 0;
}
