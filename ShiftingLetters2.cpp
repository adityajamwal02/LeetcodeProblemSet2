/*
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
Return the final string after all such shifts to s are applied.

Example 1:
Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

Example 2:
Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz"
*/

/// TLE : Brute

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts){
        int n=s.size();
        for(auto shift : shifts){
            int start=shift[0], end=shift[1], dir=shift[2];
            for(int i=start;i<=end;i++){
                if(dir==1){
                    if(s[i]=='z') s[i]='a';
                    else s[i]=s[i]+1;
                }else{
                    if(s[i]=='a') s[i]='z';
                    else s[i]=s[i]-1;
                }
            }
        }
    return s;
    }
};

/// Accepted : Optimal Solution

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts){
        int n=s.size();
        string result;
        vector<long long> ind(n+1,0);
        for(auto shift : shifts){
            int start=shift[0], end=shift[1], dir=shift[2];
            if(dir==1){
                ind[start]++;
                ind[end+1]--;
            }else{
                ind[start]--;
                ind[end+1]++;
            }
        }
        for(int i=1;i<n;i++) ind[i]+=ind[i-1];
        for(int i=0;i<n;i++){
            int shifted=((s[i]-'a')+ind[i])%26;
            if(shifted<0) shifted+=26;
            result.push_back(shifted+'a');
        }
    return result;
    }
};


