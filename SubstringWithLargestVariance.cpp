/*
The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "aababbb"
Output: 3
Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.

Example 2:
Input: s = "abcde"
Output: 0
Explanation:
No letter occurs more than once in s, so the variance of every substring is 0.
*/

/// Kadane's Modified Algorithm + Unordered_map

class Solution {
public:
    int largestVariance(string s) {
        int result=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 or mp[ch1]==0 or mp[ch2]==0) continue;

                for(int reverseCase=0;reverseCase<=1;reverseCase++){
                    int cnt1=0, cnt2=0;
                    for(auto c : s){
                        cnt1 += (c==ch1);
                        cnt2 += (c==ch2);
                        if(cnt1<cnt2){
                            cnt1=cnt2=0;
                        }
                        if(cnt1>0 and cnt2>0){
                            result=max(result,cnt1-cnt2);
                        }
                    }
                reverse(s.begin(),s.end());
                }
            }
        }
    return result;
    }
};

