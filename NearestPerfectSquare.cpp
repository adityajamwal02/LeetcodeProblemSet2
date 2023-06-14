/*
Given a number N. Find out the nearest number which is a perfect square and also the absolute difference between them.

Example 1:
Input:
N = 25
Output:
25 0
Explanation:
Since 25 is a perfect square, it is the
closest perfect square to itself and
absolute difference is 25-25=0.
Example 2:

Input:
N = 1500
Output:
1521 21
Explanation:
Two of the closest perfect squares to
1521 are 1444.Thus, 1521 is the closest
perfect square to 1500 and the absolute
difference  between them is 1521-1500=21.

Your Task:
You don't need to read input or print anything.Your Task is to complete the function nearestPerfectSquare() which takes the number N as input parameters and returns the nearest perfect square as well as the absolute difference between them.


Expected Time Complexity:O(sqrt(N))
Expected Space Auxillary:O(1)
*/


// User function template for C++

class Solution {
  public:
    vector<int> nearestPerfectSquare(int N) {
        int num=sqrt(N);
        int num2=num+1, ans;
        if(abs(num*num-N)<abs(num2*num2-N)){
            ans=num;
        }else{
            ans=num2;
        }
    return {ans*ans,abs(ans*ans-N)};
    }
};
