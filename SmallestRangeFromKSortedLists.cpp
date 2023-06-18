/*
Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

Example 1:
Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.
Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9
Your Task :

Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        int row;
        int col;

        Node(int d, int r, int c){
            data=d;
            row=r;
            col=c;
        }
};


class cmp{
public:
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<Node*,vector<Node*>,cmp> pq;
    int maxi=INT_MIN, ans=INT_MAX;
    for(int i=0;i<k;i++){
        pq.push(new Node(a[i][0],i,0));
        if(maxi<a[i][0]) maxi=a[i][0];
    }
    while(!pq.empty()){
        Node *mini=pq.top();
        pq.pop();
        int window=(maxi-mini->data)+1;
        ans=min(ans,window);
        if(mini->col+1<n){
            pq.push(new Node(a[mini->row][mini->col+1],mini->row,mini->col+1));
            maxi=max(maxi,a[mini->row][mini->col+1]);
        }else break;
    }
return ans;
}
