/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example 1:
Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect
square, floor of square_root of 5 is 2.

Example 2:
Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect
square, so its square root is 2.

Your Task:
You don't need to read input or print anything. The task is to complete the function floorSqrt() which takes x as the input parameter and return its square root.
Note: Try Solving the question without using the sqrt function. The value of x>=0.

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)
*/

/// Using Binary search


// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x)
    {
          long long int low=0, high=x, result=1;
          while(low<=high){
              long long int mid=low+(high-low)/2;
              long long int sqr=mid*mid;
              if(sqr==x){
                  return mid;
              }else if(sqr>x){
                  high=mid-1;
              }else{
                  result=mid;
                  low=mid+1;
              }
          }
        return result;
    }
};

/// sqrt function

long long int floorSqrt(long long int x)
    {
          return sqrt(x);
    }

