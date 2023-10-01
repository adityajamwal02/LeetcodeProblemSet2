/*
Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.
Note:
A string is palindromic if it reads the same forward and backward.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Example 1:
Input: s = "103301"
Output: 2
Explanation:
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301".
Two of them (both equal to "10301") are palindromic.

Example 2:
Input: s = "0000000"
Output: 21
Explanation: All 21 subsequences are "00000", which is palindromic.

Example 3:
Input: s = "9999900000"
Output: 2
Explanation: The only two palindromic subsequences are "99999" and "00000".
*/

class Solution {
public:
    int mod=1e9+7;

    int countPalindromes(string s){
        int n=s.size();
        long long dp1[n][100], dp2[n][100]; // dp1-> left side, dp2-> right side
        long long result=0;
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        // left side
        vector<int> freq(10,0);
        freq[s[0]-'0']=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<10;j++){
                if(freq[j]>0){
                    int dig=j*10+(s[i]-'0');
                    dp1[i][dig]+=freq[j];
                }
            }
            freq[s[i]-'0']++;
            for(int k=0;k<100;k++){
                dp1[i][k]+=dp1[i-1][k];
                dp1[i][k]%=mod;
            }
        }

        for(int i=0;i<freq.size();i++){
            freq[i]=0;
        }
        // right side
        freq[s[n-1]-'0']=1;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<10;j++){
                if(freq[j]>0){
                    int dig=j*10+(s[i]-'0');
                    dp2[i][dig]+=freq[j];
                }
            }
            freq[s[i]-'0']++;
            for(int k=0;k<100;k++){
                dp2[i][k]+=dp2[i+1][k];
                dp2[i][k]%=mod;
            }
        }

        for(int i=2;i<n-2;i++){
            for(int j=0;j<100;j++){
                result+=(dp1[i-1][j]*dp2[i+1][j]);
                result%=mod;
            }
        }
    return result;
    }
};


