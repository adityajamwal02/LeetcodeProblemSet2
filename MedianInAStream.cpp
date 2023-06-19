/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5,15)
1 goes to stream --> median 5 (5,15,1)
3 goes to stream --> median 4 (5,15,1 3)


Example 2:

Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5)
10 goes to stream --> median 7.5 (5,10)
15 goes to stream --> median 10 (5,10,15)
Your Task:
You are required to complete the class Solution.
It should have 2 data members to represent 2 heaps.
It should have the following member functions:
insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
*/

/// Babbar Solution

#include<bits/stdc++.h>

int signum(int a,int b){
    if(a==b)
        return 0;
    else if(a>b)
        return 1;
    else
        return -1;
}
void callMedian(int element,priority_queue<int> &maxi,
     priority_queue<int,vector<int>,greater<int> > &mini,int &median){
    switch( signum( maxi.size(),mini.size() ) ){
        case 0: if(element > median){
            mini.push(element);
            median=mini.top();
        }else{
            maxi.push(element);
            median=maxi.top();
        }
        break;
        case 1:if(element > median){
            mini.push(element);
            median=(mini.top() + maxi.top())/2;
        }else{
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median=(mini.top() + maxi.top())/2;
        }
        break;
        case -1 :if(element > median){
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median=(mini.top() + maxi.top())/2;
        }else{
            maxi.push(element);
            median=(mini.top() + maxi.top())/2;
         }
         break;
}
}

vector<int> findMedian(vector<int> &arr, int n){

	// Write your code here
      vector<int> ans;
        priority_queue<int> maxheap;
     priority_queue<int,vector<int>,greater<int> > minheap;
    int median=-1;
    for(int i=0;i<n;i++){
        callMedian(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }
    return ans;
}


/// GFG Based Solution Format

class Solution
{
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;

    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(mx.empty()||mx.top()>=x){
            mx.push(x);
        }
        else mn.push(x);
        if(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
        else if(mx.size()<mn.size()){
            mx.push(mn.top());
            mn.pop();
        }

    }

    //Function to balance heaps.
    void balanceHeaps()
    {

    }

    //Function to return Median.
    double getMedian()
    {
        if(mx.size()==mn.size())
            return mx.top()/2.0+mn.top()/2.0;

    return mx.top();
    }
};
