/*
Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.

Example 1:
Input: N = 2, S = 9
Output: 90
Explaination: It is the biggest number
with sum of digits equals to 9.

Example 2:
Input: N = 3, S = 20
Output: 992
Explaination: It is the biggest number
with sum of digits equals to 20.
Your Task:
You do not need to read input or print anything. Your task is to complete the function findLargest() which takes N and S as input parameters and returns the largest possible number. Return -1 if no such number is possible.

Expected Time Complexity: O(N)
Exepcted Auxiliary Space: O(1)
*/

class Solution{
public:
    string findLargest(int N, int S){
        string result="";
        if((S<1 and N!=1) or S>9*N) return "-1";
        if(S<9) result+=to_string(S);
        else{
            int temp=S/9;
            string nines(temp,'9');
            result+=nines;
            if(result.size()!=N){
                result+=to_string(S%9);
            }
        }
        int zero=N-result.size();
        string zeroes(zero,'0');
        result+=zeroes;
    return result;
    }
};
