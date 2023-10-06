/*
You are given an integer array nums and an integer k.
Find the longest subsequence of nums that meets the following requirements:
The subsequence is strictly increasing and
The difference between adjacent elements in the subsequence is at most k.
Return the length of the longest subsequence that meets the requirements.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
Output: 5
Explanation:
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.

Example 2:
Input: nums = [7,4,5,1,8,12,4,7], k = 5
Output: 4
Explanation:
The longest subsequence that meets the requirements is [4,5,8,12].
The subsequence has a length of 4, so we return 4.

Example 3:
Input: nums = [1,5], k = 1
Output: 1
Explanation:
The longest subsequence that meets the requirements is [1].
The subsequence has a length of 1, so we return 1.
*/


/// Segment Tree Solution


class Solution {
public:

    vector<int>seg;

    int findMax(int i,int j,int node,int &left,int &right)
    {
        if(i>right || j<left)
        return 0;

        if(i>=left && j<=right)
        return seg[node];

        int mid =i+(j-i)/2;
        int l = findMax(i,mid,2*node+1,left,right);
        int r = findMax(mid+1,j,2*node+2,left,right);

        return max(l,r);  // don't store this in segment array
    }

    int  updateTree(int i,int j,int node,int &index,int &val)
    {
        if(i>=index && j<=index)
        return seg[node]=val;

        if(i>index || j<index)
        return seg[node];

        int mid = i+(j-i)/2;

        int l=updateTree(i,mid,2*node+1,index,val);
        int r=updateTree(mid+1,j,2*node+2,index,val);

        return seg[node]=max(l,r);
    }

    int lengthOfLIS(vector<int>& nums, int k) {

        int n = nums.size();

        int m=1e5+1;
        seg.resize(4*m,0);

        int mx=0;
        for(int i=0;i<n;i++)
        {
            int low = max(1,nums[i]-k);
            int high = nums[i]-1;

            int curr = 1+findMax(0,m-1,0,low,high);
            updateTree(0,m-1,0,nums[i],curr);

            mx=max(mx,curr);
        }
        return mx;
    }
};

/// Map + B.S

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k){
        map<int,int> mp;
        for(int num : nums){
            auto it=mp.emplace(num,1).first;
            for(auto lb = mp.lower_bound(num-k);lb!=it;){
                it->second=max(it->second,lb->second+1);
                if((lb->first+1==num) or (it->first-lb->first)<=(it->second-lb->second)){
                    lb=mp.erase(lb);
                }else{
                    lb++;
                }
            }
        }
        return max_element(mp.begin(),mp.end(),[&](auto s1, auto s2){
            return s1.second<s2.second;
        })->second;
    }
};
