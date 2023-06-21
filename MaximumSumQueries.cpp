/*
You are given two 0-indexed integer arrays nums1 and nums2, each of length n, and a 1-indexed 2D array queries where queries[i] = [xi, yi].
For the ith query, find the maximum value of nums1[j] + nums2[j] among all indices j (0 <= j < n), where nums1[j] >= xi and nums2[j] >= yi, or -1 if there is no j satisfying the constraints.
Return an array answer where answer[i] is the answer to the ith query.

Example 1:
Input: nums1 = [4,3,1,2], nums2 = [2,4,9,5], queries = [[4,1],[1,3],[2,5]]
Output: [6,10,7]
Explanation:
For the 1st query xi = 4 and yi = 1, we can select index j = 0 since nums1[j] >= 4 and nums2[j] >= 1. The sum nums1[j] + nums2[j] is 6, and we can show that 6 is the maximum we can obtain.
For the 2nd query xi = 1 and yi = 3, we can select index j = 2 since nums1[j] >= 1 and nums2[j] >= 3. The sum nums1[j] + nums2[j] is 10, and we can show that 10 is the maximum we can obtain.
For the 3rd query xi = 2 and yi = 5, we can select index j = 3 since nums1[j] >= 2 and nums2[j] >= 5. The sum nums1[j] + nums2[j] is 7, and we can show that 7 is the maximum we can obtain.
Therefore, we return [6,10,7].

Example 2:
Input: nums1 = [3,2,5], nums2 = [2,3,4], queries = [[4,4],[3,2],[1,1]]
Output: [9,9,9]
Explanation: For this example, we can use index j = 2 for all the queries since it satisfies the constraints for each query.

Example 3:
Input: nums1 = [2,1], nums2 = [2,3], queries = [[3,3]]
Output: [-1]
Explanation: There is one query in this example with xi = 3 and yi = 3. For every index, j, either nums1[j] < xi or nums2[j] < yi. Hence, there is no solution.
*/


/// Segment Trees + Binary Search + Reverse Sort

class Solution {
public:
    void update(int s, int e, const int index, const int value, int node, vector<int> &segtree){
        if(s==e){
            segtree[node]=max(segtree[node],value);
            return;
        }
        int mid=(s+e)/2;
        if(index<=mid) update(s,mid,index,value,2*node+1,segtree);
        else update(mid+1,e,index,value,2*node+2,segtree);
        segtree[node]=max(segtree[2*node+1],segtree[2*node+2]);
    }
    int query(int s, int e, const int l, const int r, int node, const vector<int> &segtree){
        if(l>e or r<s) return -1;
        if(l<=s and e<=r) return segtree[node];
        int mid=(s+e)/2;
        int option1=query(s,mid,l,r,2*node+1,segtree);
        int option2=query(mid+1,e,l,r,2*node+2,segtree);
    return max(option1,option2);
    }
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();
        int m=queries.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={nums1[i],nums2[i]};
        }
        sort(v.begin(),v.end());
        set<int> st;
        for(auto &y : nums2){
            st.insert(y);
        }
        for(auto &node : queries){
            st.insert(node[1]);
        }
        map<int,int> coordinates;
        int tdx=0;
        for(int x : st){
            coordinates[x]=tdx;
            tdx++;
        }
        vector<int> segtree(4*tdx,-1);
        for(int i=0;i<m;i++){
            queries[i].push_back(i);
        }
        sort(queries.rbegin(),queries.rend());
        int index=n-1;
        vector<int> result(m,-1);
        for(auto q: queries){
            int x=q[0];
            int y=q[1];
            int z=q[2];
            while(index>=0 and v[index].first>=x){
                update(0,tdx-1,coordinates[v[index].second],v[index].first+v[index].second,0,segtree);
                index--;
            }
            int ans=query(0,tdx-1,coordinates[y],tdx-1,0,segtree);
            result[z]=ans;
        }
    return result;
    }
};

/// Solution 2 : PQ

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<vector<int>> vp;
        int n = queries.size();
        for(int i = 0; i < n; i++)
            vp.push_back({queries[i][0], queries[i][1], i});

        sort(vp.begin(), vp.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        priority_queue<vector<int>> p,q;
        for(int i = 0; i < nums1.size(); i++)
            p.push({nums1[i] + nums2[i], nums1[i], nums2[i]});

        vector<int> ans(n, -1);
        for(auto v: vp) {
            while(!p.empty()) {
                if(p.top()[1] < v[0])
                    p.pop();
                // first is greater and second is smaller then keep it save in next queue because it can be use further
                else if(p.top()[2] < v[1])
                    q.push(p.top()), p.pop();
                else
                    break;
            }

            if(!p.empty())
                ans[v[2]] = p.top()[0];

            while(!q.empty())
                p.push(q.top()), q.pop();
        }

        return ans;
    }
};
