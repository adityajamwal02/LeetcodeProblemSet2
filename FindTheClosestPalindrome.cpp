/*
Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
The closest is defined as the absolute difference minimized between two integers.

Example 1:
Input: n = "123"
Output: "121"

Example 2:
Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
*/

class Solution {
public:
    string nearestPalindromic(string str){
        int n=str.size();
        if(n==1) return to_string(stoi(str)-1);
        vector<long> nums;  // for cases: one digit less, one digit more, same no. of digits
        nums.push_back(pow(10,n-1)-1);
        nums.push_back(pow(10,n)+1);
        // Same no. of digits
        int mid=(n+1)/2;
        long prefix=stol(str.substr(0,mid));
        vector<long> v={prefix,prefix+1,prefix-1};
        for(long it : v){
            string pref=to_string(it);
            if(n%2!=0) pref.pop_back();
            reverse(pref.begin(),pref.end());
            string s=to_string(it)+pref;
            nums.push_back(stol(s));
        }
        long result, num=stol(str), minDiff=LONG_MAX;
        for(int i=0;i<5;i++){
            if(nums[i]!=num and abs(nums[i]-num)<minDiff){
                minDiff=abs(nums[i]-num);
                result=nums[i];
            }else if(abs(nums[i]-num)==minDiff){
                result=min(result,nums[i]);
            }
        }
    return to_string(result);
    }
};
