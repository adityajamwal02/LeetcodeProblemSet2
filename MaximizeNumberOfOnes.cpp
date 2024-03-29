/*
Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.


Example 1:

Input:
N = 3
arr[] = {1, 0, 1}
M = 1
Output:
3
Explanation:
Maximum subarray is of size 3
which can be made subarray of all 1 after
flipping one zero to 1.
Example 2:

Input:
N = 11
arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}
M = 2
Output:
8
Explanation:
Maximum subarray is of size 8
which can be made subarray of all 1 after
flipping two zeros to 1.


Your Task:
Complete the function findZeroes() which takes array arr and two integers n, m, as input parameters and returns an integer denoting the answer.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int zero=0, i=0, maxOnes=0;
        for(int j=0;j<n;j++){
            if(arr[j]==0){
                zero++;
            }
            while(zero>m){
                if(arr[i]==0){
                    zero--;
                }
                i++;
            }
            maxOnes=max(maxOnes,j-i+1);
        }
    return maxOnes;
    }
};
