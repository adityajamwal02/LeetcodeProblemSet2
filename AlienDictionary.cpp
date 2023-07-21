/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.


Example 1:
Input:
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is
'b', 'd', 'a', 'c' Note that words are sorted
and in the given language "baa" comes before
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Example 2:
Input:
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.

Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)
*/

// User function Template for C++

class Solution{
    private:
    vector<int> topoSort(int v, vector<int> adj[]){
        int indegree[v]={0};
        for(int i=0;i<v;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    return result;
    }

    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(), s2.size());
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        vector<int> result = topoSort(K,adj);
        string ans = "";
        for(auto i : result){
            ans=ans+char(i+'a');
        }
    return ans;
    }
};


/// Coding ninjas

#include<bits/stdc++.h>
using namespace std;

vector<char> getAlienLanguage(string* dict, int n)
{
    vector<int> adj[26];
    int indegree[26] = { 0 };
    for(int i=0;i<n-1;i++){
        for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++){
            if(dict[i][j]!=dict[i+1][j]){
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                indegree[dict[i+1][j]-'a']++;
                break;
            }
        }
    }
    vector<char> result;
    queue<int> q;
    for(int i=0;i<26;i++){
        if(indegree[i]==0){
            result.push_back('a'+i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        result.push_back('a'+curr);
        for(auto it : adj[curr]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return result;
}

