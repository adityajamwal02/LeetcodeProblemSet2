/*
Given a string s containing 0's and 1's. You have to return the smallest positive integer C, such that the binary string can be cut into C pieces and each piece should be of the power of 5  with no leading zeros.
Note: The string s is a binary string. And if no such cuts are possible, then return -1.

Example 1:
Input:
s = "101101101"
Output:
3
Explanation:
We can split the given string into
three 101s, where 101 is the binary
representation of 5.

Example 2:
Input:
s = "00000"
Output:
-1
Explanation:
0 is not a power of 5.
Your Task:
Your task is to complete the function cuts() which take a single argument(string s). You need not take any input or print anything. Return an int C if the cut is possible else return -1.

Expected Time Complexity: O(|s|*|s|*|s|).
Expected Auxiliary Space: O(|s|).
*/

/// dp

class Solution{
    public:
    int dp[51];

bool isPowerOfFive(long long y){
    if(y==1){
        return true;
    }
    long long x=5;
    long long expo=1;
    while(expo<y){
        expo=expo*x;
    }
    return expo==y;
}

long long helper(string &s, int curr){
    if(curr<0){
        return 0;
    }
    if(dp[curr]!=-1){
        return dp[curr];
    }
    long long res=INT_MAX;
    long long val=0;
    long long power=0;
    for(int i=curr;i>=0;i--){
        if(s[i]=='1'){
            val+=pow(2,power);
        }
        if(isPowerOfFive(val)==true && s[i]!='0'){ // cannot have leading zeros
            long long temp=helper(s,i-1);
            if(temp!=INT_MAX){
                res=min(res,1+temp);
            }
        }
        power++;
    }
    return dp[curr]=res;
}

int cuts(string s){
    memset(dp,-1,sizeof(dp));
    int res=helper(s,s.size()-1);
    return res==INT_MAX ? -1 : res;
}
};
