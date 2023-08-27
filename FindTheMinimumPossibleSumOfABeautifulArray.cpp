/*
You are given positive integers n and target.
An array nums is beautiful if it meets the following conditions:
nums.length == n.
nums consists of pairwise distinct positive integers.
There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
Return the minimum possible sum that a beautiful array could have.

Example 1:
Input: n = 2, target = 3
Output: 4
Explanation: We can see that nums = [1,3] is beautiful.
- The array nums has length n = 2.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 4 is the minimum possible sum that a beautiful array could have.

Example 2:
Input: n = 3, target = 3
Output: 8
Explanation: We can see that nums = [1,3,4] is beautiful.
- The array nums has length n = 3.
- The array nums consists of pairwise distinct positive integers.
- There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
It can be proven that 8 is the minimum possible sum that a beautiful array could have.

Example 3:
Input: n = 1, target = 1
Output: 1
Explanation: We can see, that nums = [1] is beautiful.
*/

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_map<int,int> mp;
        long long num=1, result=0;
        for(int i=0;i<n;i++){
            int next=target-num;
            if(mp.find(next)==mp.end()){
                result+=num;
                mp[num]=1;
                num++;
            }else{
                num++;
                i--;
            }
        }
    return result;
    }
};
