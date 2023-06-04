/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which takes the array of integers arr, n, and x as parameters and returns an integer denoting the answer.
If x is not present in the array (arr) then return 0.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)
*/

//User function template for C++
class Solution{
public:
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int firstOcc(int arr[], int n, int x){
	    int low=0, high=n-1, ans=-1;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        if(arr[mid]==x){
	            ans=mid;
	            high=mid-1;
	        }else if(arr[mid]>x){
	            high=mid-1;
	        }else{
	            low=mid+1;
	        }
	    }
    return ans;
	}
	int lastOcc(int arr[], int n, int x){
	    int low=0, high=n-1, ans=-1;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        if(arr[mid]==x){
	            ans=mid;
	            low=mid+1;
	        }else if(arr[mid]>x){
	            high=mid-1;
	        }else{
	            low=mid+1;
	        }
	    }
    return ans;
	}
	int count(int arr[], int n, int x) {
	    int val1=firstOcc(arr,n,x);
	    int val2=lastOcc(arr,n,x);
	    if(val1==-1 and val2==-1) return 0;
	return (val2-val1+1);
	}
};
