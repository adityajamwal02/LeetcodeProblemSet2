/*
A positive integer is magical if it is divisible by either a or b.
Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

Example 1:
Input: n = 1, a = 2, b = 3
Output: 2

Example 2:
Input: n = 4, a = 2, b = 3
Output: 6
*/

class Solution {
public:
    int mod=1e9+7;
    long long int gcd(int a, int b){
        if(a==0) return b;
        else return gcd(b%a,a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long int low=1, high=(long long int)n*min(a,b);
        long long int lcm=(a*b)/gcd(a,b);
        while(low<high){
            long long int mid = low+(high-low)/2;
            long long int factor = mid/a + mid/b - mid/lcm;
            if(factor<n){
                low=mid+1;
            }else{
                high=mid;
            }
        }
    return low%mod;
    }
};
