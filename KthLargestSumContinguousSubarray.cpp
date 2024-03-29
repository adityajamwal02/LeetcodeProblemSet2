/*
You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements.

Example 1:
Input:
N = 3
K = 2
Arr = {3,2,1}
Output:
5
Explanation:
The different subarray sums we can get from the array
are = {6,5,3,2,1}. Where 5 is the 2nd largest.

Example 2:
Input:
N = 4
K = 3
Arr = {2,6,4,1}
Output:
11
Explanation:
The different subarray sums we can get from the array
are = {13,12,11,10,8,6,5,4,2,1}. Where 11 is the 3rd largest.

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the array Arr[] and its size N as inputs and returns the Kth largest subarray sum.

Expected Time Complexity: O(N2 * log K)
Expected Auxiliary Space: O(K)
*/

// Generate all continguous subarray sums, put in Max-heap and Remove K-1, Return Top of MAxHeap

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int> pq;
        int currSum=0;
        for(int i=0;i<N;i++){
            currSum+=Arr[i];
            for(int j=i+1;j<N;j++){
                currSum+=Arr[j];
                pq.push(currSum);
            }
            currSum=0;
        }
        for(auto it : Arr){
            pq.push(it);
        }
        K--;
    while(K--){
        pq.pop();
    }
    return pq.top();
    }
};
