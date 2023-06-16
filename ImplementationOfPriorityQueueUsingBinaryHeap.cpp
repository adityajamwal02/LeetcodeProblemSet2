/*
Given a binary heap implementation of Priority Queue. Extract the maximum element from the queue i.e. remove it from the Queue and return it's value.

Example 1:
Input: 4 2 8 16 24 2 6 5
Output: 24
Priority Queue after extracting maximum: 16 8 6 5 2 2 4

Example 2:
Input: 64 12 8 48 5
Output: 64
Priority Queue after extracting maximum: 48 12 8 5

Your Task:
Complete the function extractMax() which extracts the maximum element, i.e. remove it from the Queue and return it's value.
*/

// User function Template for C++
// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].

class Solution {
  public:
    int extractMax() {
        int result=H[0];
        int last=H[s];
        H[0]=H[s];
        s--;
        shiftDown(0);
    return result;
    }
};
