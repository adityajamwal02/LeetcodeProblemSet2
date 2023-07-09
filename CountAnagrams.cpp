/*
You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.
A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7.

Example 1:
Input: s = "too hot"
Output: 18
Explanation: Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".

Example 2:
Input: s = "aa"
Output: 1
Explanation: There is only one anagram possible for the given string.
*/


class Solution {
public:
    int mod=1e9+7;

    long long power(long long x, long long y){
        long long res=1;
        x%=mod;
        while(y>0){
            if(y&1) res=(res*x)%mod;

            y>>=1;
            x=(x*x)%mod;
        }
    return res;
    }

    long long modInverse(int n){
        return power(n,mod-2);
    }
    unsigned long long Combinations(int n, int r){
        if(n<r) return 0;
        if(r==0) return 1;
        long long factorial[n+1];
        factorial[0]=1;
        for(int i=1;i<=n;i++){
            factorial[i]=(factorial[i-1]*i)%mod;
        }
    return (factorial[n] * modInverse(factorial[r])%mod * modInverse(factorial[n-r])%mod )%mod;
    }
    int countAnagrams(string s) {
        int counter=0;
        unordered_map<char,int> mp;
        long long result=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                for(int j=0;j<26;j++){
                    if(mp['a'+j]) result=(result*Combinations(counter,mp['a'+j]))%mod;
                    counter-=mp['a'+j];
                    mp['a'+j]=0;
                }
            }else{
                counter++;
                mp[s[i]]++;
            }
        }
        for(int j=0;j<26;j++){
            if(mp['a'+j]) result=(result*Combinations(counter,mp['a'+j]))%mod;
            counter-=mp['a'+j];
            mp['a'+j]=0;
        }
    return (int)(result%mod);
    }
};
