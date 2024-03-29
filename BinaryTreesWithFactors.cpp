/*
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
*/

/// Map DP Solution

class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr){
        int n=arr.size(), result=0;
        sort(arr.begin(),arr.end());
        unordered_map<int, long long> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 and mp.find(arr[i]/arr[j])!=mp.end()){
                    mp[arr[i]]=(mp[arr[i]]+(mp[arr[j]]*(mp[arr[i]/arr[j]]))%mod)%mod;
                }
            }
        }
        for(auto it : mp){
            result=(result%mod+(it.second)%mod)%mod;
        }
    return result;
    }
};

