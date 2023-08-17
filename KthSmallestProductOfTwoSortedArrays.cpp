/*
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

Example 1:
Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.

Example 2:
Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.

Example 3:
Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.
*/

/// Similar to Median of 2 sorted arrays and kth element of 2 sorted arrays

class Solution {
public:

    int findmaxIndex(vector<int> &nums2, long long val, long long midVal){
        int low=0, high=nums2.size()-1, result=-1;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(val*nums2[mid]<=midVal){
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return result+1;
    }

    int findminIndex(vector<int> &nums, long long val, long long midVal){
        int low=0, high=nums.size()-1, result=high+1;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(val*nums[mid]<=midVal){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return nums.size()-result;
    }

    bool isValid(vector<int> &nums1, vector<int> &nums2, long long mid, long long k){
        long long counter=0;
        for(int i=0;i<nums1.size();i++){
            long long val=nums1[i];
            if(val==0 and mid>=0) counter+=nums2.size();
            else if(val>0) counter+=findmaxIndex(nums2,val,mid);
            else if(val<0) counter+=findminIndex(nums2,val,mid);
        }
    return counter>=k;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low=-1e10, high=1e10, result=-1;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(isValid(nums1,nums2,mid,k)){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return result;
    }
};
