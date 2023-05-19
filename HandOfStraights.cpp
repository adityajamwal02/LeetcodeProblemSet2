/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
*/


/// Map Solution

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        for(auto x=mp.begin();x!=mp.end();){
            if(mp[x->first]>0){
                for(int i=0;i<groupSize;i++){
                    if(mp[x->first+i]>0) mp[x->first+i]--;
                    else return false;
                }
            }else{
                x++;
            }
        }
    return true;
    }
};

/// PQ solution

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k) return false;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto &[a,b] : mp){
            pq.push({a,b});
        }
        while(pq.size()>k-1){
            vector<pair<int,int>> temp(k);
            for(int i=0;i<k;i++){
                temp[i]=pq.top();
                pq.pop();
            }
            int mn=INT_MAX;
            for(int i=0;i<k-1;i++){
                if(temp[i].first!=temp[i+1].first-1) return false;
            }
            for(auto &p : temp){
                mn=min(mn,p.second);
            }
            for(auto &p : temp){
                if(p.second-mn){
                    pq.push({p.first, p.second-mn});
                }
            }
        }
    return pq.empty();
    }
};
