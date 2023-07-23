/*
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
Return the maximum number of events you can attend.

Example 1:
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

Example 2:
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
*/

/// greedy Solution (Sort + PQ)

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int counter=0, day=0, i=0, n=events.size();
        sort(events.begin(),events.end(),[&](vector<int> &a, vector<int> &b){
            if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        while(i<n or !pq.empty()){
            if(pq.empty()){
                day=events[i][0];
            }
            while(i<n and events[i][0]<=day){
                pq.push(events[i][1]);
                i++;
            }
            day++;
            counter++;
            pq.pop();
            while(!pq.empty() and pq.top()<day){
                pq.pop();
            }
        }
    return counter;
    }
};
