/*
Given a positive integer N., The task is to find the value of    \sum_{i=1}^{i=n} F(i)  where function F(i) for the number i be defined as the sum of all divisors of �i�.

Example 1:
Input:
N = 4
Output:
15
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15

Example 2:
Input:
N = 5
Output:
21
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
F(5) = 1 + 5 = 6
ans = F(1) + F(2) + F(3) + F(4) + F(5)
    = 1 + 3 + 4 + 7 + 6
    = 21
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfDivisors() which takes an integer N as an input parameter and returns the answer of the problem asked.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

/// TLE

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long result=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    result+=j;
                }
            }
        }
    return result;
    }
};


/// Accepted

//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long result=0;
        for(int i=1;i<=N;i++){
            result+=(i*(N/i));
        }
    return result;
    }
};



