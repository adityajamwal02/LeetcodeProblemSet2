/*
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        set<int> st(arr,arr+n);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : st){
            if(it>0){
                pq.push(it);
            }
        }
        int i=1;
        while(!pq.empty()){
            if(pq.top()==i){
                pq.pop();
                i++;
            }else{
                return i;
            }
        }
    return i;
    }
};


/// Optimized Approach

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
       vector<bool>a(n+1,false);
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0 || arr[i]>n){
                continue;
            }
            a[arr[i]]=true;
        }
        for(int i=1;i<=n;i++)
            if(a[i]==false)
                return i;
        return n+1;
    }
};
