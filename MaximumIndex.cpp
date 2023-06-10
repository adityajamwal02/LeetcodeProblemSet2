/*
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.


Example 1:

Input:
N = 2
A[] = {1, 10}
Output:
1
Explanation:
A[0]<A[1] so (j-i) is 1-0 = 1.
Example 2:

Input:
N = 9
A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array A[1] < A[7]
satisfying the required
condition(A[i] < A[j]) thus giving
the maximum difference of j - i
which is 6(7-1).


Your Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code. Return 0 in case no such index is found.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

/// Brute

class Solution{
    public:

    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N)
    {
        int maxLen=INT_MIN;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(A[j]>=A[i] and j>=i){
                    if((j-i)>maxLen){
                        maxLen=(j-i);
                    }
                }
            }
        }
    return maxLen==INT_MIN ? 0 : maxLen;
    }
};


/// Optimized

class Solution{
    public:

    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N)
    {
       vector<int> minLeft(N), maxRight(N);
       minLeft[0]=A[0];
       maxRight[N-1]=A[N-1];
       for(int i=1;i<N;i++){
           minLeft[i]=min(A[i],minLeft[i-1]);
       }
       for(int i=N-2;i>=0;i--){
           maxRight[i]=max(A[i],maxRight[i+1]);
       }
       int i=0, j=0, result=0;
       while(i<N and j<N){
           if(minLeft[i]<=maxRight[j]){
               result=max(result,j-i);
               j++;
           }else{
               i++;
           }
       }
    return result;
    }
};

