/*
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
Return an array answer where answer[i] is the answer to the ith query.

Example 1:
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8]
Explanation:
The binary representation of the elements in the array are:
1 = 0001
3 = 0011
4 = 0100
8 = 1000
The XOR values for queries are:
[0,1] = 1 xor 3 = 2
[1,2] = 3 xor 4 = 7
[0,3] = 1 xor 3 xor 4 xor 8 = 14
[3,3] = 8

Example 2:
Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
*/


/// Prefix + Bit Manipulation


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefix(n), result;
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=(prefix[i-1]^arr[i]);
        }
        for(auto it : queries){
            int left=it[0];
            int right=it[1];
            if(left==0){
                result.push_back(prefix[right]);
            }else{
                result.push_back(prefix[left-1]^prefix[right]);
            }
        }
    return result;
    }
};

/// Mo's Algorithm Solution

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        int Q = queries.size();
        int B = max(1, N / int(sqrt(Q)));
        for (int i = 0; i < Q; ++i) {
            queries[i].emplace_back(i);
        }
        sort(begin(queries), end(queries), [B = B](auto& lhs, auto& rhs) {
            int b1 = lhs[0] / B, b2 = rhs[0] / B;
            return (b1 == b2) ? (lhs[1] < rhs[1]) : (b1 < b2);
        });
        vector<int> ans(Q, 0);
        int l = 0, r = 0, val = arr[0];
        for (vector<int>& query : queries) {
            while (l < query[0]) {
                val ^= arr[l];
                ++l;
            }
            while (l > query[0]) {
                val ^= arr[l - 1];
                --l;
            }
            while (r < query[1]) {
                val ^= arr[r + 1];
                ++r;
            }
            while (r > query[1]) {
                val ^= arr[r];
                --r;
            }
            ans[query[2]] = val;
        }
        return ans;
    }
};
