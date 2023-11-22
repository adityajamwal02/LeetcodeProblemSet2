/*
Given an array of positive integers arr (not necessarily distinct), return the lexicographically
largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.
Note that a swap exchanges the positions of two numbers arr[i] and arr[j]

Example 1:
Input: arr = [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.

Example 2:
Input: arr = [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.

Example 3:
Input: arr = [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.
*/

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr){
        int n=arr.size(), index=n-2, maxi=INT_MIN, position;
        while(index>=0){
            if(arr[index]>arr[index+1]) break;
            index--;
        }
        if(index<0) return arr;
        for(int i=index+1;i<n;i++){
            if(arr[i]<arr[index] and arr[i]>maxi){
                maxi=arr[i];
                position=i;
            }
        }
        swap(arr[position],arr[index]);

    return arr;
    }
};
