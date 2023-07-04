/*
You are given array nums of n elements and integer K, and count the number of subarrays that has k odd numbers.

Example1:

Input:
n = 5
nums = [1,1,2,1,1]
k = 3
Output:
2
Explanation:
There are 2 subarrays with k odds [1,1,2,1] and [1,2,1,1]
Example 2:

Input:
n=3
nums = [2,4,6]
k = 1
Output:
0
Your Task:
You don't have to read input or print anything. Your task is to complete the function countSubarray() which takes the integer n and array nums and integer K as input and returns the count of subarray having k odds number.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
*/


class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        int i=0, j=0, odd=0, counter=0, prefix=0;
        while(j<n){
            if(nums[j]%2!=0){
                odd++;
                prefix=0;
            }
            while(i<=j and odd==k){
                if(nums[i]%2!=0){
                    odd--;
                }
                prefix++;
                i++;
            }
        counter=counter+prefix;
        j++;
        }
    return counter;
    }
};
