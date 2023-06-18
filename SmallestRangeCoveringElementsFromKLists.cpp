/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

*/

class Node{
    public:
        int data;
        int row;
        int col;
        int size;

        Node(int d, int r, int c, int sz){
            data=d;
            row=r;
            col=c;
            size=sz;
        }
};


class cmp{
public:
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        int k=a.size();
        priority_queue<Node*,vector<Node*>,cmp> pq;
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0;i<k;i++){
            int sz=a[i].size();
            pq.push(new Node(a[i][0],i,0,sz));
            if(maxi<a[i][0]) maxi=a[i][0];
            if(mini>a[i][0]) mini=a[i][0];
        }
        int start=mini, end=maxi;
        while(!pq.empty()){
            Node *temp=pq.top();
            pq.pop();
            mini=temp->data;
            if(maxi-mini < end-start){
                start=mini;
                end=maxi;
            }
            if(temp->col+1<temp->size){
                pq.push(new Node(a[temp->row][temp->col+1],temp->row,temp->col+1,temp->size));
                maxi=max(maxi,a[temp->row][temp->col+1]);
            }else break;
        }
    return {start,end};
    }
};
