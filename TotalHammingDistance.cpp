/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

Example 1:
Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Example 2:
Input: nums = [4,14,4]
Output: 4
*/

/// Brute Approach

class Solution {
public:
    int countDifferentBits(int x, int y){
        int temp=0;
        for(int i=0;i<32;i++){
            if(((x>>i)&1)!=((y>>i)&1)) temp++;
        }
    return temp;
    }

    int totalHammingDistance(vector<int>& nums){
        int counter=0, n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                counter+=countDifferentBits(nums[i],nums[j]);
            }
        }
    return counter;
    }
};

/// Accepted Solution

class Solution {
public:
    int totalHammingDistance(vector<int>& nums){
        int result=0, n=nums.size();
        for(int i=0;i<32;i++){
            int counter=0;
            for(auto num : nums){
                counter+=(1^(((num&(1<<i))!=0)));
            }
            result+=(counter*(n-counter));
        }
    return result;
    }
};
