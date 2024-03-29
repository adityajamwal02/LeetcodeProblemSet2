/*
Given an increasing sequence a[], we need to find the K-th missing contiguous element in the increasing sequence which is not present in the sequence. If no k-th missing element is there output -1.

Example 1:
Input : arr[ ] = {1, 3, 4, 5, 7} and K = 2
Output : 6
Explanation:
K = 2, We need to find the 2nd missing
number in the array. Missing numbers are
2 and 6. So 2nd missing number is 6.

Example 2:
Input : arr[ ] = {1, 2, 3, 4, 5, 6} and K = 1
Output :  -1

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function KthMissingElement() that takes an array (arr), sizeOfArray (n), an integer K and return the Kth missing number if present otherwise returns -1. The driver code takes care of the printing.

*/

int KthMissingElement(int a[], int n, int k)
{
    if(a[n-1]==n+a[0]-1) return -1;
    int low=0, high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=a[mid]-a[0]-mid;
        if(missing<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(high>=0 and low<n) return a[0]+high+k;

return -1;
}
