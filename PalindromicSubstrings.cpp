/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

/// Solution 1

class Solution {
public:
    int countSubstrings(string s){
        int i=0, j=0, n=s.size(), oddCount=0, evenCount=0;
        for(int x=0;x<n;x++){
            i=x;
            j=x;
            while(i<n and j>=0){
                if(s[i]==s[j]) oddCount++;
                else break;
            i++;
            j--;
            }
        }
        for(int x=1;x<n;x++){
            i=x;
            j=x-1;
            while(i<n and j>=0){
                if(s[i]==s[j]) evenCount++;
                else break;
            i++;
            j--;
            }
        }
    return evenCount+oddCount;
    }
};

/// Solution 2

int CountPS(char S[], int N)
{
    int counter=0;
    for(int i=0;i<N;i++){
        int left=i, right=i;
        while(left>=0 and right<N and S[right]==S[left]){
            counter++;
            left--;
            right++;
        }
        right=i+1;
        left=i;
        while(left>=0 and right<N and S[right]==S[left]){
            counter++;
            left--;
            right++;
        }
    }
    return counter;
}
