/*
You are given an array of N integers arr, find the count of reverse pairs.
A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met:
0 <= i < j < N
arr[i] > 2 * arr[j]

Example 1:
Input:
N = 6
arr = [3, 2, 4, 5, 1, 20]
Output:
3
Explanation:
The Reverse pairs are
(i)  (0, 4), arr[0] = 3, arr[4] = 1, 3 > 2(1)
(ii) (2, 4), arr[2] = 4, arr[4] = 1, 4 > 2(1)
(iii)(3, 4), arr[3] = 5, arr[4] = 1, 5 > 2(1)

Example 2:
Input:
N = 5
arr= [2, 4, 3, 5, 1]
Output:
3
Explanation:
(i)   (1, 4), arr[1] = 4, arr[4] = 1, 4 > 2 * 1
(ii)  (2, 4), arr[2] = 3, arr[4] = 1, 3 > 2 * 1
(iii) (3, 4), arr[3] = 5, arr[4] = 1, 5 > 2 * 1

Your Task:
Complete the function countRevPairs(), which takes integer a list of N integers as input and returns the count of Reverse Pairs.

Expected Time Complexity: O(N logN)
Expected Auxiliary Space: O(N)
*/


// User function Template for C++

 int merge(vector<int> &arr, int left, int mid, int right){
        int counter = 0;
        int j = mid+1;
        for(int i=left;i<=mid;i++){
            while(j <= right and arr[i] > 2LL*arr[j]) j++;
            counter += j - (mid+1);
        }
        vector<int> temp;
        int i = left;
        j = mid+1;
        while(i <= mid and j <= right){
            if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }

        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= right) temp.push_back(arr[j++]);

        for(int i=left;i<=right;i++) arr[i] = temp[i - left];

    return counter;
    }

int mergeSort(vector<int> &arr, int low, int high){
    if(low>=high) return 0;
    int counter=0;
    int mid=(high+low)/2;
    counter+=mergeSort(arr,low,mid);
    counter+=mergeSort(arr,mid+1,high);
    counter+=merge(arr,low,mid,high);
    return counter;
}

class Solution {
  public:
    int countRevPairs(int n, vector<int> arr) {
        return mergeSort(arr,0,n-1);
    }
};
