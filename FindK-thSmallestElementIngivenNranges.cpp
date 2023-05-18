/*
Given n ranges of the form [p, q] which denotes all the numbers in the range [p, p + 1, p + 2,...q].  Given another integer q denoting the number of queries. The task is to return the kth smallest element for each query (assume k>1) after combining all the ranges.
In case the kth smallest element doesn't exist return -1.

Example 1:

Input:
n = 2, q = 3
range[] = {{1, 4}, {6, 8}}
queries[] = {2, 6, 10}
Output:
2 7 -1
Explanation:
After combining the given ranges,
the numbers become 1 2 3 4 6 7 8. As here 2nd
element is 2, so we print 2. As 6th element is
7, so we print 7 and as 10th element doesn't
exist, so weprint -1.
Example 2:

Input:
n = 2, q = 2
range[] = {{2, 6}, {5, 7}}
queries[] = {5, 8}
Output:
6 -1
Explantion:
After combining the ranges, we'll take Union of
range= {2,3,4,5,6,7}, here  5th smallest number
will be 6 and 8th smallest number does not exists.
Your Task:
You don't need to read input or print anything. Your task is to complete the function kthSmallestNum() which takes a n * 2 array denoting the ranges and an array denoting the queries.

Expected Time Complexity: O(nlogn+q*n)
Expected Auxiliary Space: O(q)
*/

/// TLE

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        set<int> st;
        for(int i=0;i<n;i++){
            int low=range[i][0];
            int high=range[i][1];
            for(int j=low;j<=high;j++){
                st.insert(j);
            }
        }
        vector<int> v(st.begin(), st.end());
        vector<int> result;
        int sz=v.size();
        for(int i=0;i<q;i++){
            if(queries[i]>sz){
                result.push_back(-1);
            }else{
                result.push_back(v[queries[i]-1]);
            }
        }
    return result;
    }
};

/// PQ Solution

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:range)
        {
            pq.push({it[0],it[1]});
        }

        vector<pair<int,int>>v;
        while(pq.size()>1)
        {
            auto it=pq.top();
            pq.pop();
            auto it1=pq.top();
            pq.pop();

            if(it.second>=it1.first)
            {
                pq.push({it.first,max(it1.second,it.second)});
            }
            else
            {
                pq.push(it1);
                v.push_back({it});
            }
        }

        v.push_back(pq.top());

        vector<int>ans;


        for(int i=0;i<queries.size();i++)
        {
            for(auto it:v)
            {
                int low=it.first;
                int high=it.second;
                int size=high-low+1;

                if(size>=queries[i])
                {
                ans.push_back(low+queries[i]-1);
                break;
                }
                else
                queries[i]-=size;
            }
            if(ans.size()==i)
            ans.push_back(-1);
        }

        return ans;
    }

};
