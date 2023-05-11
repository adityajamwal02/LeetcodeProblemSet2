/*
Given a string, S.The string can contain small case English letters or '?'. You can replace '?' with any small English letter. Now if it is possible to make the string S a palindrome after replacing all '?' then find the palindromic string with a minimum ascii sum of differences of adjacent characters. Otherwise, return -1.

Example 1:
Input: S = a???c??c????
Output: 4
Explanation:
We can see that we can make the string
palindrome. Now to get minimum ascii sum we should
replace all the '?' between 'a' and 'c' with
'b' and all the '?' between two 'c' with 'c'.
So after replacing all the '?' the string:
abbbccccbbba.
The sum of differences of adjacent characters is 4.

Example 2:
Input: S = a???c??c???c
Output: -1
Explanation:
It is not possible to make the string palindrome.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimumSum() which takes a string S input parameter and returns an integer denoting the sum of differences of adjacent characters. If it is not possible to make string palindrome, return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/


// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j){
            if(s[i]!=s[j] and s[i]!='?' and s[j]!='?') return -1;
            if(s[i]=='?' and s[j]!='?') s[i]=s[j];
            else if(s[i]!='?' and s[j]=='?') s[j]=s[i];
            else if(i!=0 and s[i-1]!='?' and s[i]=='?' and s[j]=='?'){
                s[i]=s[i-1];
                s[j]=s[j+1];
            }
            i++;
            j--;
        }
        int result=0;
        for(int i=1;i<=n/2;i++){
            if(s[i]=='?') continue;
            if(s[i-1]!='?') result+=(2*abs(s[i]-s[i-1]));
        }
    return result;
    }
};
