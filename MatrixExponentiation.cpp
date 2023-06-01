/*
Given an equation of the form f(n) = f(n-1) + f(n-2) where f(0) = 1, f(1) = 1 , the task is to find the nth term of this sequence.

Example 1:
Input: n = 3
Output: 3
Explanation: f(3) = f(2) + f(1) = 3

Example 2:
Input: n = 2
Output: 2
Explanation: f(2) = f(1) + f(0) = 2

Yout Task:
You don't need to read or print anything. Your task is to complete the function FindNthTerm() which takes n as input parameter and returns nth term mod 10^9+7 .

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(K) where K is constant.
*/


class Solution {
public:
    const  int mod=1e9+7;
    void multiply(long long int f[2][2], long long int m[2][2])
    {
    int x = ((f[0][0]%mod * m[0][0]%mod)%mod + (f[0][1]%mod * m[1][0]%mod)%mod)%mod;
    int y = ((f[0][0]%mod * m[0][1]%mod)%mod + (f[0][1]%mod * m[1][1]%mod)%mod)%mod;
    int z = ((f[1][0]%mod * m[0][0]%mod)%mod + (f[1][1]%mod * m[1][0]%mod)%mod)%mod;
    int w = ((f[1][0]%mod * m[0][1]%mod)%mod + (f[1][1]%mod * m[1][1]%mod)%mod)%mod;

    f[0][0] = x;
    f[0][1] = y;
    f[1][0] = z;
    f[1][1] = w;
    }
    void power(long long int f[2][2], long long int n)
    {
        if(n==0 || n==1)
        return ;

        long long int m[2][2]={{1,1},{1,0}};

        power(f,n/2);
        multiply(f,f);
        if(n%2!=0)
        multiply(f,m);
    }
    int FindNthTerm(long long int n) {
        n=n+1;
        long long int f[2][2] = {{1,1},{1,0}};
        if(n==0)
            return 0;
        power(f,n-1);
    return f[0][0];
    }
};
