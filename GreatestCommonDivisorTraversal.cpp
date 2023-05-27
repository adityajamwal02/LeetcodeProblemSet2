/*
You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.
Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.
Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

Example 1:
Input: nums = [2,3,6]
Output: true
Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
To go from index 0 to index 1, we can use the sequence of traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1.
To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.

Example 2:
Input: nums = [3,9,5]
Output: false
Explanation: No sequence of traversals can take us from index 0 to index 2 in this example. So, we return false.

Example 3:
Input: nums = [4,3,12,8]
Output: true
Explanation: There are 6 possible pairs of indices to traverse between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals exists for each pair, so we return true.
*/

class Solution {
public:
    class UnionFind{
        private:
            vector<int> parent, rank;
        public:
            UnionFind(int n){
                parent.resize(n);
                rank.resize(n,1);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            }
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }
        return parent[x];
        }
        void unionByRank(int x, int y){
            int rx=find(x);
            int ry=find(y);
            if(rx!=ry){
                if(rank[rx]<rank[ry]){
                    parent[rx]=ry;
                }else if(rank[rx]>rank[ry]){
                    parent[ry]=rx;
                }else{
                    parent[rx]=ry;
                    rank[ry]++;
                }
            }
        }
    };

    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        UnionFind u(n);
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    mp[j].push_back(i);
                    while(nums[i]%j==0){
                        nums[i]/=j;
                    }
                }
            }
            if(nums[i]>1){
                mp[nums[i]].push_back(i);
            }
        }
        for(auto it : mp){
            vector<int> &ind=it.second;
            for(int i=1;i<ind.size();i++){
                u.unionByRank(ind[i-1],ind[i]);
            }
        }
        int root=u.find(0);
        for(int i=1;i<n;i++){
            if(u.find(i)!=root){
                return false;
            }
        }
    return true;
    }
};
