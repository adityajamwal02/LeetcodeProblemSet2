/*
A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Example 1
Input:
N = 5
arr[] = {4 ,5 ,1 ,2 ,3}
Output: 1
Explanation: 1 is the minimum element inthe array.

Example 2
Input:
N = 7
arr[] = {10, 20, 30, 40, 50, 5, 7}
Output: 5
Explanation: Here 5 is the minimum element.


Your Task:
Complete the function findMin() which takes an array arr[] and n, size of the array as input parameters, and returns the minimum element of the array.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(log N).

Constraints:
*/

/// Linear O(n)

int findMin(int arr[], int n){
        //complete the function here
    return *min_element(arr,arr+n);
    }

/// Binary Search O(logn)

class Solution{
public:
    int findMin(int arr[], int n){
       int low=0, high=n-1, minVal=INT_MAX;
       while(low<=high){
           if(arr[low]<arr[high]){
               minVal=min(minVal,arr[low]);
               break;
           }
           int mid=low+(high-low)/2;
           if(arr[low]<=arr[mid]){
               minVal=min(minVal,arr[low]);
               low=mid+1;
           }else{
               minVal=min(minVal,arr[mid]);
               high=mid-1;
           }
       }
    return minVal;
    }
};
