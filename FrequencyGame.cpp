/*
Given an array A of size N. The elements of the array consist of positive integers. You have to find the largest element with minimum frequency.

Example 1:
Input:
5
2 2 5 50 1
Output:
50
Explanation :
All elements are having frequency 1 except 2.
50 is the maximum element with minimum frequency.

Example 2:
Input:
4
3 3 5 5
Output:
5
Explanation:
Both 3 and 5 have the same frequency, so 5 should be returned.
User Task:
Your task is to complete the provided function LargButMinFreq(A, n) which accepts array A and n. Hence you have to return the largest element with minimum frequency.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 <= N <= 105
1 <= A[i] <= 106
*/

// User function Template for C++

class Solution{
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.first==b.first){
            return a.second>b.second;
        }
    return a.first<b.first;
    }
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it : mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),cmp);
    return v[0].second;
    }
};
