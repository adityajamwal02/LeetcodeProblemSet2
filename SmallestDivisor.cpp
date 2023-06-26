/*
You are given an array of integers nums and an integer K, your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer K.
Each result of the division is rounded to the nearest integer greater than or equal to that element. For Example: 7/3 = 3.

Example:
Input:
A = [1 2 5 9]
6
Output:
5
Explanation:
If the divisor is 5 the sum will be 5 (1+1+1+2), which is less than 6.

Your Task:
Complete the function int smallestDivisor(), which takes a vector nums and an integer K and returns the smallest integer as asked.
Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).
*/

class Solution {
  public:
    bool isCheck(vector<int> &nums, int k, int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((1.0*nums[i])/mid);
        }
    return sum<=k;
    }
    int smallestDivisor(vector<int>& nums, int K) {
        int result=*max_element(nums.begin(),nums.end());
        int low=1, high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isCheck(nums,K,mid)){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return result;
    }
};
