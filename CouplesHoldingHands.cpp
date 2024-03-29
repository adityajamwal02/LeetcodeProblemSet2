/*
There are n couples sitting in 2n seats arranged in a row and want to hold hands.
The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

Example 1:
Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

Example 2:
Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.
*/

/// Union find solution

class Solution {
public:
    vector<int> parent;

    int findParent(int node){
        if(parent[node]==node) return node;
    return parent[node]=findParent(parent[node]);
    }

    bool makeUnion(int x, int y){
        int u=findParent(x), v=findParent(y);
        if(u==v) return false;
        parent[v]=u;
    return true;
    }

    int minSwapsCouples(vector<int>& row){
        int n=row.size(), result=0;
        if(n==0) return 0;
        parent.resize(n);
        for(int i=0;i<n;i+=2){
            parent[row[i]]=row[i];
            parent[row[i+1]]=row[i];
        }
        for(int i=0;i<n;i+=2){
            if(makeUnion(i,i+1)) result++;
        }
    return result;
    }
};
