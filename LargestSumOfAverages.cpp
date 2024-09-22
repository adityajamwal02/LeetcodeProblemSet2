// 813. Largest Sum of Averages

class Solution {
public:
    vector<vector<double>> dp;
    
    double solve(int left, vector<int> &nums, int k){
        if(left>=nums.size()) return 0;
        
        if(k==0){
            int right=nums.size();
            double score=0.0;
            double sum=accumulate(nums.begin()+left,nums.begin()+right,0);
            score+=(sum/(right-left));
        return score;
        }

        if(dp[left][k]!=-1) return dp[left][k];
        double maxScore=0;

        for(int i=1;left+i<=nums.size();i++){
            double curr=0.0;
            double sum=accumulate(nums.begin()+left,nums.begin()+left+i,0);
            curr+=(sum/i);
            curr+=(solve(left+i,nums,k-1));
            maxScore=max(curr,maxScore);
        }
    return dp[left][k]=maxScore;
    }

    double largestSumOfAverages(vector<int>& nums, int k){
        int n=nums.size();
        dp.resize(n,vector<double>(k,-1));
    return solve(0,nums,k-1);
    }
};
