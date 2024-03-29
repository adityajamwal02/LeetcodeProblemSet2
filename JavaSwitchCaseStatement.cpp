/*
Given an integer choice denoting the choice of the user and a list containing the single value R or two values L and B depending on the choice.
If the user's choice is 1, calculate the area of the circle having the given radius(R).
Else if choice is 2, calculate the area of the rectangle with given length(L) and breadth(B).



Example 1:

Input:
choice = 1,
R = 5
Output: 78.53981633974483
Explaination: The choice is 1.
So we have to calculate the area of the circle.


Example 2:

Input:
choice = 2,
L = 5, B = 10
Output: 50
Explaination: Here we have to calculate the
area of the rectangle.


Your Task:
You do not need to read input or print anything. Your task is to complete the function switchCase() which takes choice and a list arr[], containing the single value R or the two values L and B, as input parameters. It should return area of the desired geomatrical figure.
Note: Use Math.PI for the value of pi.



Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)


*/

class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        switch(choice){
            case 1: return  M_PI*arr[0]*arr[0];
            case 2: return arr[0]*arr[1];
        }
    return -1;
    }
};
