/*
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.
You can do the following operation any number of times:
Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].
Return the minimum total cost such that all the elements of the array nums become equal.

Example 1:
Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.

Example 2:
Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.
*/


/// Prefix Sum + Sorting

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        long long result=LONG_MAX;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        vector<long long> prefix_cost(n,0), prefix_total(n,0);
        prefix_cost[0]=v[0].second*1LL;
        prefix_total[0]=(v[0].first*1LL)*(v[0].second*1LL);
        for(int i=1;i<n;i++){
            prefix_cost[i]=prefix_cost[i-1]+v[i].second;
        }
        for(int i=1;i<n;i++){
            prefix_total[i]=prefix_total[i-1]+((v[i].first*1LL)*(v[i].second*1LL));
        }
        for(int i=0;i<n;i++){
            long long cost=(prefix_total[n-1]-prefix_total[i]);
            cost=cost-((v[i].first*1LL)*(prefix_cost[n-1]-prefix_cost[i]));
            long long x=0;
            if(i-1>=0){
                x=(v[i].first*1LL)*(prefix_cost[i-1]);
                x-=prefix_total[i-1];
            }
            cost+=x;
            result=min(result,cost);
        }
    return result;
    }
};

/// Binary Search

#define ll long long
class Solution {
public:
    ll isPossible(vector<int> &nums, vector<int> &cost , ll target)
    {
        ll count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=cost[i]*(abs(nums[i]-target));
        }
        return count;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());
        ll ans=LLONG_MAX;
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            ll x=isPossible(nums,cost,mid);
            ll y=isPossible(nums,cost,mid+1);
            if(x<y)
            {
                ans=min(ans,x);
                right=mid-1;
            }
            else
            {
                ans=min(ans,y);
                left=mid+2;
            }
        }
        return ans;
    }
};
