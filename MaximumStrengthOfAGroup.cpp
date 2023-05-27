/*
You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].
Return the maximum strength of a group the teacher can create.

Example 1:
Input: nums = [3,-1,-5,2,5,-9]
Output: 1350
Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.

Example 2:
Input: nums = [-4,-5,-4]
Output: 20
Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.
*/


 class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> less, great;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                less.push_back(nums[i]);
            }else if(nums[i]>0){
                great.push_back(nums[i]);
            }
        }
        long long ans=0;
        sort(great.begin(),great.end());
        sort(less.begin(),less.end());
        for(int i=0;i<less.size();i++){
            if(i==0){
                ans=(long long)less[i];
            }else{
                if(less.size()%2==0){
                    long long neg=less[i];
                    ans*=neg;
                }else{
                    if(i<less.size()-1){
                        long long neg=less[i];
                        ans*=neg;
                    }
                }
            }
        }
        long long ans2=0;
        for(int i=0;i<great.size();i++){
            if(ans2==0)
                ans2=(long long)great[i];
            else{
                long long pos=great[i];
                ans2*=pos;
            }
        }

        if(ans>0 and ans2>0){
            return (long long)(ans*ans2);
        }else if(ans>0){
            return ans;
        }else if(ans2>0){
            return ans2;
        }else{
            return 0;
        }
    }
};
