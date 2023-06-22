/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

/// Solution 1:

class Solution {
public:
    long long helper(vector<int> &piles, long long mid){
        long long totalHours=0, n=piles.size();
        for(int i=0;i<n;i++){
            totalHours+=ceil((double)piles[i]/(double)mid);
        }
    return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(piles.begin(),piles.end());
        int result=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hours=helper(piles,mid);
            if(hours<=h){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return result;
    }
};


/// Solution 2

class Solution {
public:
    bool eatable(vector<int> piles,int mid, int h, int n){
        int count=0;
        for(int i=0;i<n;i++){
            int temp=piles[i]/mid;
            count+=temp+1;
            if(piles[i]%mid==0)
                count--;
        }
    return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int ans=-1,s=1,e=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(eatable(piles,mid,h,n)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
    return ans;
    }
};
