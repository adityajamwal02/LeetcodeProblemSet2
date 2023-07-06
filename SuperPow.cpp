/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:
Input: a = 2, b = [3]
Output: 8

Example 2:
Input: a = 2, b = [1,0]
Output: 1024

Example 3:
Input: a = 1, b = [4,3,3,8,5,2]
Output: 1
*/

class Solution {
public:
    int mod=1337;
    int helper(int a, int k){
        a%=mod;
        int result=1;
        for(int i=0;i<k;i++){
            result*=a;
            result%=mod;
        }
    return result;
    }
    int superPow(int a, vector<int>& b) {
        int n=b.size();
        if(n==0) return 1;
        int last=b.back();
        b.pop_back();
        int part1=helper(a,last);
        int part2=helper(superPow(a,b),10);

    return (part1*part2)%mod;
    }
};
