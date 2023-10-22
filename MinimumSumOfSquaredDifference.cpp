/*
You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.
The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.
You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.
Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.
Note: You are allowed to modify the array elements to become negative integers.

Example 1:
Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0.
The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.

Example 2:
Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation: One way to obtain the minimum sum of square difference is:
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be:
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.
*/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2){
        long long n=nums1.size(), result=0, k=k1+k2;
        unordered_map<long long,long long> mp;
        for(int i=0;i<n;i++){
            long long diff=abs(nums1[i]-nums2[i]);
            mp[diff]++;
        }
        priority_queue<pair<long long, long long>> pq;
        for(auto it : mp){
            pq.push({it.first,it.second});
        }
        pq.push({0,0});
        while(!pq.empty() and k>0 and pq.top().first!=0){
            auto it1=pq.top();
            pq.pop();
            auto it2=pq.top();
            long long temp=(it1.first-it2.first)*it1.second;
            if(k>=temp){
                pq.pop();
                k-=temp;
                pq.push({it2.first,it2.second+it1.second});
            }else{
                long long mini=min(k,it1.second);
                k-=mini;
                if(mini!=0){
                    pq.push({it1.first-1,mini});
                }
                if(it1.second!=mini){
                    pq.push({it1.first,it1.second-mini});
                }
            }
        }
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long val=it.first, freq=it.second;
            result+=(val*val*freq);
        }
    return result;
    }
};
