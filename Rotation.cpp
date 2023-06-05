/*
Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

Example 1:
Input:
N = 5
Arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4.
The original sorted array is 1 2 3 4 5.
We can see that the array was rotated
1 times to the right.

Example 2:
Input:
N = 5
Arr[] = {1, 2, 3, 4, 5}
Output: 0
Explanation: The given array is not rotated.
Your Task:
Complete the function findKRotation() which takes array arr and size n, as input parameters and returns an integer representing the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(1)
*/

class Solution{
public:
	int findKRotation(int arr[], int n) {
	    int low=0, high=n-1, ans=INT_MAX, index=-1;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        if(arr[low]<=arr[high]){
	            if(arr[low]<ans){
	                index=low;
	                ans=arr[low];
	            }
	            break;
	        }
	        if(arr[low]<=arr[mid]){
	            if(arr[low]<ans){
	                index=low;
	                ans=arr[low];
	            }
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	            if(arr[mid]<ans){
	                index=mid;
	                ans=arr[mid];
	            }
	        }
	    }
	return index;
	}
};
