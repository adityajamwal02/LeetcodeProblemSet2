/*
Implement pow(x, n) % M.
In other words, given x, n and M, find (xn) % M.

Example 1:
Input:
x = 3, n = 2, m = 4
Output:
1
Explanation:
32 = 9. 9 % 4 = 1.

Example 2:
Input:
x = 2, n = 6, m = 10
Output:
4
Explanation:
26 = 64. 64 % 10 = 4.

Your Task:
You don't need to read or print anything. Your task is to complete the function PowMod() which takes integers x, n and M as input parameters and returns xn % M.

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)
*/

/// Modular Exponentiation for large numbers

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    if(x==0) return 0;
		    if(n==0) return 1;
		    if(n==1) return x%M;
		    long long int y;
		    if(n%2==0){
		        y=PowMod(x,n/2,M)%M;
		        y=(y*y)%M;
		    }else{
		        y=x%M;
		        y=(y*PowMod(x,n-1,M)%M)%M;
		    }
		return (long long int)(y+M)%M;
		}
};
