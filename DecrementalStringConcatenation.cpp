/*
You are given a 0-indexed array words containing n strings.
Let's define a join operation join(x, y) between two strings x and y as concatenating them into xy. However, if the last character of x is equal to the first character of y, one of them is deleted.
For example join("ab", "ba") = "aba" and join("ab", "cde") = "abcde".
You are to perform n - 1 join operations. Let str0 = words[0]. Starting from i = 1 up to i = n - 1, for the ith operation, you can do one of the following:

Make stri = join(stri - 1, words[i])
Make stri = join(words[i], stri - 1)
Your task is to minimize the length of strn - 1.

Return an integer denoting the minimum possible length of strn - 1.

Example 1:
Input: words = ["aa","ab","bc"]
Output: 4
Explanation: In this example, we can perform join operations in the following order to minimize the length of str2:
str0 = "aa"
str1 = join(str0, "ab") = "aab"
str2 = join(str1, "bc") = "aabc"
It can be shown that the minimum possible length of str2 is 4.

Example 2:
Input: words = ["ab","b"]
Output: 2
Explanation: In this example, str0 = "ab", there are two ways to get str1:
join(str0, "b") = "ab" or join("b", str0) = "bab".
The first string, "ab", has the minimum length. Hence, the answer is 2.

Example 3:
Input: words = ["aaa","c","aba"]
Output: 6
Explanation: In this example, we can perform join operations in the following order to minimize the length of str2:
str0 = "aaa"
str1 = join(str0, "c") = "aaac"
str2 = join("aba", str1) = "abaaac"
It can be shown that the minimum possible length of str2 is 6.
*/


/// Memoization + Recursion

class Solution {
public:
    int helper(char s, char e, int index, vector<string> &words, vector<vector<vector<int>>> &dp){
        if(index==words.size()) return 0;
        if(dp[index][s-'a'][e-'a']!=-1) return dp[index][s-'a'][e-'a'];
        int curr_size=words[index].size();

        int op1=curr_size+helper(s,words[index].back(),index+1,words,dp);
        if(e==words[index][0]) op1--;

        int op2=curr_size+helper(words[index][0],e,index+1,words,dp);
        if(words[index].back()==s) op2--;

    return dp[index][s-'a'][e-'a']=min(op1,op2);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        int n=words.size();
        string word=words[0];
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(26,vector<int>(26,-1)));

    return word.size()+helper(word[0],word[word.size()-1],1,words,dp);
    }
};

/// Tabulation

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& a) {
        int n = a.size();
        int dp[n + 1][26][26];
        memset(dp, -1, sizeof(dp));
        for(int i = n; i>=1; --i){
            for(int fc = 0; fc < 26; ++fc){
                for(int lc = 0; lc < 26; ++lc){
                    if(i == n) dp[i][fc][lc] = 0;
                    else{
                        int len = a[i].size();
                        int ans1 = dp[i + 1][fc][a[i].back() - 'a'] + len;
                        if(a[i][0] - 'a' == lc) --ans1;
                        int ans2 = dp[i + 1][a[i][0] - 'a'][lc] + len;
                        if(a[i].back() - 'a' == fc) --ans2;
                        dp[i][fc][lc] = min(ans1, ans2);
                    }
                }
            }
        }
        return a[0].size() + dp[1][a[0][0] - 'a'][a[0].back() - 'a'];
    }
};
