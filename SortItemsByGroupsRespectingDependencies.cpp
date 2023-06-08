/*
There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
Return a sorted list of the items such that:
The items that belong to the same group are next to each other in the sorted list.
There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
Return any solution if there is more than one solution and return an empty list if there is no solution.

Example 1:
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]

Example 2:
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
*/

class Solution {
public:
    vector<int> topoSort(vector<unordered_set<int>> &vec, vector<int> indegree){
        vector<int> result;
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            result.push_back(curr);
            for(auto temp : vec[curr]){
                indegree[temp]--;
                if(indegree[temp]==0){
                    q.push(temp);
                }
            }
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]>0) return {};
        }
    return result;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m++;
            }
        }
        vector<unordered_set<int>> graphGroup(m), graphItem(n);
        vector<int> ingroup(m), initem(n);
        for(int i=0;i<n;i++){
            int to_group=group[i];
            for(auto from : beforeItems[i]){
                int from_group=group[from];
                if(from_group!=to_group and !graphGroup[from_group].count(to_group)){
                    graphGroup[from_group].insert(to_group);
                    ingroup[to_group]++;
                }
                if(!graphItem[from].count(i)){
                    graphItem[from].insert(i);
                    initem[i]++;
                }
            }
        }
        vector<int> sortGroup=topoSort(graphGroup,ingroup);
        vector<int> sortItem=topoSort(graphItem,initem);
        if(sortGroup.empty() or sortItem.empty()) return {};
        vector<vector<int>> groupToItem(m);
        for(auto it : sortItem){
            groupToItem[group[it]].push_back(it);
        }
        vector<int> ans;
        for(auto it : sortGroup){
            for(auto item : groupToItem[it]){
                ans.push_back(item);
            }
        }
    return ans;
    }
};

