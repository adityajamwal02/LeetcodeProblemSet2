/*
Given two given numbers a and b where 1<=a<=b, find the number of perfect squares between a and b (a and b inclusive).

Example 1:
Input:
a = 9, b = 25
Output:
3
Explanation:
There are 3 perfect squares between 9
and 25. They are 9, 16, and 25.

Example 2:
Input:
a = 1, b = 7
Output:
2
Explanation:
There are 2 perfect squares between 1
and 7. They are 1, and 4.

Your Task:
You don't need to read input or print anything. Your task is to complete the function numOfPerfectSquares() which takes 2 Integers a and b as input and returns the number of perfect squares between a and b.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/

class Solution {
  public:
    int numOfPerfectSquares(int a, int b) {
        int counter=0;
        for(int i=1;i<=sqrt(b);i++){
            if(i*i>=a and i*i<=b){
                counter++;
            }
        }
    return counter;
    }
};
