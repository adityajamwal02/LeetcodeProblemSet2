/*
Given an array in such a way that the elements stored in array are in increasing order initially and then after reaching to a peak element, the elements stored are in decreasing order. Find the highest element.
Note: A[i] != A[i+1]

Example 1:
Input:
11
1 2 3 4 5 6 5 4 3 2 1
Output: 6
Explanation: Highest element is 6.

Example 2:
Input:
5
1 2 3 4 5
Output: 5
Explanation: Highest element is 5.

Your Task:
You don't need to read or print anything. Your task is to complete the function findPeakElement() which takes the array as the input parameter and returns the highest element.

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)
*/

/// Binary Search

class Solution {
public:
    int findPeakElement(vector<int>& a)
    {
        int result=a[0];
        int n=a.size(), low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            result=max(result,a[mid]);
            if(mid-1>=0 and a[mid]<a[mid-1]){
                high=mid-1;
            }else if(mid+1<=n-1 and a[mid]<a[mid+1]){
                low=mid+1;
            }else{
                return result;
            }
        }
    return result;
    }
};


/// Direct Solution

class Solution {
public:
    int findPeakElement(vector<int>& a)
    {
        return *max_element(a.begin(),a.end());
    }
};
