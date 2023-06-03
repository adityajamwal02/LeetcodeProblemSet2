/*
For a given 3 digit number, find whether it is armstrong number or not. An Armstrong number of three digits is an integer such that the sum of the cubes of its digits is equal to the number itself. Return "Yes" if it is a armstrong number else return "No".
NOTE: 371 is an Armstrong number since 33 + 73 + 13 = 371

Example 1:
Input: N = 153
Output: "Yes"
Explanation: 153 is an Armstrong number
since 13 + 53 + 33 = 153.
Hence answer is "Yes".

Example 2:
Input: N = 370
Output: "Yes"
Explanation: 370 is an Armstrong number
since 33 + 73 + 03 = 370.
Hence answer is "Yes".

Your Task:
You dont need to read input or print anything. Complete the function armstrongNumber() which takes n as input parameter and returns "Yes" if it is a armstrong number else returns "No"..

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/


// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int result=0, total=n;
        while(n>0){
            int temp=n%10;
            result+=(temp*temp*temp);
            n=n/10;
        }
        if(result==total) return "Yes";
    return "No";
    }
};
