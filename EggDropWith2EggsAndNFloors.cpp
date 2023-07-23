/*
You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input: n = 2
Output: 2
Explanation: We can drop the first egg from floor 1 and the second egg from floor 2.
If the first egg breaks, we know that f = 0.
If the second egg breaks but the first egg didn't, we know that f = 1.
Otherwise, if both eggs survive, we know that f = 2.

Example 2:
Input: n = 100
Output: 14
Explanation: One optimal strategy is:
- Drop the 1st egg at floor 9. If it breaks, we know f is between 0 and 8. Drop the 2nd egg starting from floor 1 and going up one at a time to find f within 8 more drops. Total drops is 1 + 8 = 9.
- If the 1st egg does not break, drop the 1st egg again at floor 22. If it breaks, we know f is between 9 and 21. Drop the 2nd egg starting from floor 10 and going up one at a time to find f within 12 more drops. Total drops is 2 + 12 = 14.
- If the 1st egg does not break again, follow a similar process dropping the 1st egg from floors 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100.
Regardless of the outcome, it takes at most 14 drops to determine f.
*/

/// Mathematical Solution

class Solution {
public:
    int twoEggDrop(int n) {
        // Using sum of natural numbers, to get the minimum value of f (f*(f+1)/2 >=n)
        double numerator=sqrt(1+8*n)-1;
    return ceil(numerator/2);
    }
};

/// DP Solution


class Solution {
    int dp[1001][3];
    int Solve(int egg, int floor){
        if(floor == 0 || floor == 1){
            return floor;
        }
        if(egg == 1){
            return floor;
        }
        if(dp[floor][egg] != -1) return dp[floor][egg];
        int l=1, h = floor, m;
        int ans = INT_MAX;
        while(l<=h){
            m = l + (h-l)/2;
            int lower=0;
            if(dp[m-1][egg-1] != -1){
                lower = dp[m-1][egg-1];
            }
            else{
                lower = Solve(egg-1, m-1);
                dp[m-1][egg-1] = lower;
            }
            int upper=0;
            if(dp[floor-m][egg] != -1){
                upper = dp[floor-m][egg];
            }
            else{
                upper = Solve(egg, floor-m);
                dp[floor-m][egg] = upper;
            }
            int temp = 1 + max(lower, upper);
            dp[floor][egg] = temp;
            ans = min(ans, temp);
            if(lower<upper){
                l = m+1;
            }
            else if(lower>upper){
                h = m-1;
            }
            else{
                break;
            }
        }
        return dp[floor][egg] = ans;
    }
public:
    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        return Solve(2, n);
    }
};
