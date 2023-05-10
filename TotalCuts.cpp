/*
You are given an array A of N integers and an integer K, and your task is to find the total number of cuts that you can make such that for each cut these two conditions are satisfied
1. A cut divides an array into two parts equal or unequal length (non-zero).
2. Sum of the largest element in the left part and the smallest element in the right part is greater than or equal to K.

Example 1:

Input:
N=3
K=3
A[]={1,2,3}
Output:
2
Explanation:
Two ways in which array is divided to satisfy above conditions are:
{1} and {2,3} -> 1+2>=3(satisfies the condition)
{1,2} and {3} -> 2+3>=3(satisfies the condition)
Example 2:

Input:
N=5
K=5
A[]={1,2,3,4,5}
Output:
3
Explanation:
{1,2} and {3,4,5} -> 2+3>=5
{1,2,3} and {4,5} -> 3+4>=5
{1,2,3,4} and {5} -> 4+5>=5
Your Task:
You don't need to read input or print anything. Your task is to complete the function totalCuts() which takes two integers N, K, and an array A of size N as input parameters, and returns an integer representing the total number of cuts that satisfy both conditions.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> largest, smallest;
        int maxVal=INT_MIN;
        for(int i=0;i<N-1;i++){
            if(A[i]>maxVal){
                maxVal=A[i];
            }
            largest.push_back(maxVal);
        }
        int minVal=INT_MAX;
        for(int i=N-1;i>0;i--){
            if(A[i]<minVal){
                minVal=A[i];
            }
            smallest.push_back(minVal);
        }
        reverse(smallest.begin(), smallest.end());
        int index=0, i=0;
        for(i=0;i<largest.size();i++){
            if(largest[i]+smallest[i]>=K){
                index=i;
                break;
            }
        }
        if(i==largest.size()) return 0;
    return largest.size()-index;
    }
};
