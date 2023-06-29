/*
Given a positive number N and a number D.  Find the count of positive numbers smaller or equal to  N such that the difference between the number and sum of its digits is greater than or equal to given specific value D.

Example 1:

Input:
N = 13 , D = 2
Output:
4
Explanation:
There are 4 numbers satisfying the
Conditions. These are 10,11,12 and 13.
Example 2:

Input:
N = 14 , D = 3
Output:
5
Explanation:
There are 5 numbers satisfying the
Conditions. These are 10,11,12,13 and 14.
Your Task:
You don't need to read input or print anything. Your task is to complete the function getCount() which takes 2 integers N and D as input and returns the answer.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(1)
*/


/// Binary Search

class Solution {
  public:
    long long digitSum(long long n){
        long long result=0;
        while(n){
            result+=(n%10);
            n/=10;
        }
    return result;
    }
    long long getCount(long long N , long long D) {
        long long low=1, high=N;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid-digitSum(mid)<D){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return N-high;
    }
};
