/*
Given and integer N.Calculate the sum of series 13 + 23 + 33 + 43 + … till N-th term.

Example 1:

Input:
N=5
Output:
225
Explanation:
13+23+33+43+53=225
Example 2:

Input:
N=7
Output:
784
Explanation:
13+23+33+43+53+63+73=784

Your Task:
You don't need to read input or print anything.Your task is to complete the function sumOfSeries() which takes the integer N as parameter and returns the sum of the cubes of the first N natural numbers.


Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)
*/



class Solution {
  public:
    long long  helper(long long i, long long n, long long result){
        if(i>n) return result;
        long long ans=(i*i*i);
        result+=ans;
    return helper(i+1,n,result);
    }
    long long sumOfSeries(long long N) {
        long long result=helper(1,N,result);
    return result;
    }
};
