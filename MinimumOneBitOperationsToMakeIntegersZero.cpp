/*
Given an integer n, you must transform it into 0 using the following operations any number of times:
Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0.

Example 1:
Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.

Example 2:
Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.
*/

class Solution {
public:
    string decimalToBinary(int n){
        string result;
        while(n>0){
            result+=to_string(n%2);
            n/=2;
        }
        reverse(result.begin(),result.end());

    return result;
    }

    int helper(string str, unordered_map<string,int> &dp){
        if(str.empty()) return 0;
        else if(dp.count(str)!=0) return dp[str];

        int n=str.size();
        string left="1", right;

        if(n-2>0){
            string temp(n-2,'0');
            left+=temp;
        }

        for(int i=1;i<n;i++){
            if(!right.empty() or str[i]=='1') right.push_back(str[i]);
        }
        dp[str]=1+(2*helper(left,dp))-helper(right,dp);

    return dp[str];
    }

    int minimumOneBitOperations(int n){
        string str=decimalToBinary(n);
        unordered_map<string,int> dp;   // map (seen)
        dp["1"]=1;
        dp["0"]=0;

    return helper(str,dp);
    }
};
