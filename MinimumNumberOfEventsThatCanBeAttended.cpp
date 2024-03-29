/*
You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
Return the maximum sum of values that you can receive by attending events.

Example 1:
Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

Example 2:
Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.

Example 3:
Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
*/

/// Recursive Solution

class Solution {
public:
    int solve(int i, int n, int k, vector<vector<int>> &events){
        if(i>=n or k==0) return 0;
        int j;
        for(j=i+1;j<n;j++){
            if(events[j][0]>events[i][1]){
                break;
            }
        }
    return max(solve(i+1,n,k,events), events[i][2]+solve(j,n,k-1,events));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
    return solve(0,n,k,events);
    }
};



/// Memoization

class Solution {
public:
    int solve(int i, int n, int k, vector<vector<int>> &events, vector<vector<int>> &dp){
        if(i>=n or k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int j;
        for(j=i+1;j<n;j++){
            if(events[j][0]>events[i][1]){
                break;
            }
        }
    return dp[i][k]=max(solve(i+1,n,k,events,dp), events[i][2]+solve(j,n,k-1,events,dp));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
    return solve(0,n,k,events,dp);
    }
};

/// Best Solution (DP + Binary Search)

class Solution {
public:
    int solve(int i, int n, int k, vector<vector<int>> &events, vector<vector<int>> &dp){
        if(i>=n or k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int j;
        vector<int> temp={events[i][1],INT_MAX,INT_MAX};
        j=upper_bound(events.begin()+i+1, events.end(), temp) - events.begin();
        for(j=i+1;j<n;j++){
            if(events[j][0]>events[i][1]){
                break;
            }
        }
    return dp[i][k]=max(solve(i+1,n,k,events,dp), events[i][2]+solve(j,n,k-1,events,dp));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
    return solve(0,n,k,events,dp);
    }
};
