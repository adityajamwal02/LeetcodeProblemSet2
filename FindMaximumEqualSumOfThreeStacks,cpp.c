/*
Given three stacks S1, S2 & S3 of size N1, N2 & N3 respectively, having only Positive Integers. The task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. Stacks are represented as an array, and the first index of the array represents the top element of the stack.

Example 1:

Input:
N1 = 3, N2 = 4, N3 = 2
S1 = {4,2,3}
S2 = {1,1,2,3}
S3= {1,4}
Output:
5
Explanation:
We can pop 1 element from the 1st stack, and 2
elements from the 2nd stack. Now remaining elements
yield the equal sum of the three stacks, that is 5.
Example 2:

Input:
N1 =2, N2 = 1, N3 = 3
S1 = {4,7}
S2 = {10}
S3 = {1,2,3}
Output:
0
Explanation:
We will never get an equal sum after popping
some elements, so the answer will be 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxEqualSum() which takes the arrays S1[], S2[], and S3[] and their sizes N1, N2, and N3 as inputs and returns the maximum equal sum we can obtain.

Expected Time Complexity: O(N1+N2+N3)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N1, N2, N3 <= 105
1 <= S1[i], S2[i], S3[i] <= 103
The sum, N1+N2+N3 doesn't exceed 106
*/

//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1=0, sum2=0, sum3=0;
        for(auto it : S1) sum1+=it;
        for(auto it : S2) sum2+=it;
        for(auto it : S3) sum3+=it;
        int i=0, j=0, k=0, result=0;
        while(i<N1 and j<N2 and k<N3){
            if(sum1==sum2 and sum2==sum3) return sum1;
            int mini=min({sum1,sum2,sum3});
            while(i<N1 and sum1>mini){
                sum1=sum1-S1[i];
                i++;
            }
            while(j<N2 and sum2>mini){
                sum2=sum2-S2[j];
                j++;
            }
            while(k<N3 and sum3>mini){
                sum3=sum3-S3[k];
                k++;
            }
        }
    return 0;
    }
};

