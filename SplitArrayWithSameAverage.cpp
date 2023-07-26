/*
You are given an integer array nums.
You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
Return true if it is possible to achieve that and false otherwise.
Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.

Example 1:
Input: nums = [1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.

Example 2:
Input: nums = [3,1]
Output: false
*/

class Solution {
public:
    vector<vector<int>> findAllCombinations(vector<int> nums){
        int n=nums.size();
        vector<vector<int>> st(n+1);
        for(int i=0;i<(1<<n);i++){
            int subsetSum=0, sz=0, k=0, temp=i;
            while(temp!=0){
                if((temp&1)==1){
                    sz++;
                    subsetSum+=nums[k];
                }
                k++;
                temp>>=1;
            }
            st[sz].push_back(subsetSum);
        }
    return st;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return false;
        if(n==2) return (nums[0]==nums[1]);
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> arr1=findAllCombinations(vector<int>(nums.begin(),nums.begin()+n/2+1));
        vector<vector<int>> arr2=findAllCombinations(vector<int>(nums.begin()+n/2+1,nums.end()));
        for(int i=0;i<n/2;i++){
            sort(arr2[i].begin(),arr2[i].end());
        }
        // For Binary Search part
        for(int i=0;i<arr1.size();i++){
            for(auto it : arr1[i]){
                for(int j=0;j<arr2.size();j++){
                    if(i+j==0 or i+j==n) continue;
                    double temp = ((1.0*total*(i+j))/n)-it;
                    if(ceil(temp)!=temp) continue;
                    if(binary_search(arr2[j].begin(),arr2[j].end(),(int)temp)) return true;
                }
            }
        }
    return false;
    }
};
