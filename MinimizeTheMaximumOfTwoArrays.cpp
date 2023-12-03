/*
We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:
arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
No integer is present in both arr1 and arr2.
Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

Example 1:
Input: divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
Output: 4
Explanation:
We can distribute the first 4 natural numbers into arr1 and arr2.
arr1 = [1] and arr2 = [2,3,4].
We can see that both arrays satisfy all the conditions.
Since the maximum value is 4, we return it.

Example 2:
Input: divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1
Output: 3
Explanation:
Here arr1 = [1,2], and arr2 = [3] satisfy all conditions.
Since the maximum value is 3, we return it.

Example 3:
Input: divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
Output: 15
Explanation:
Here, the final possible arrays can be arr1 = [1,3,5,7,9,11,13,15], and arr2 = [2,6].
It can be shown that it is not possible to obtain a lower maximum satisfying all conditions.
*/

class Solution {
public:
    int minimizeSet(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2) {
        long long ans = INT_MAX, lccmm = lcm(divisor1,divisor2), l = 0, r = 1e12;
        while(l <= r){
            long long mid = (l + r)/2;
            long long rem = mid, z = 0;
            long long rem1 = max(z,uniqueCnt1 - min(uniqueCnt1,mid/divisor2 - mid/lccmm));
            long long rem2 = max(z,uniqueCnt2 - min(uniqueCnt2,mid/divisor1 - mid/lccmm));
            rem = rem - mid/divisor2 - mid/divisor1 + mid/lccmm;
            if(rem1 + rem2 > rem) l = mid + 1;
            else{
                if(mid%divisor1 == 0 and mid%divisor2 == 0) ans = min(ans,mid + 1);
                else ans = min(ans,mid);
                r = mid - 1;
            }
        }
    return ans;
    }
};
