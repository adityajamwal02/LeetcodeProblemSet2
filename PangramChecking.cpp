/*
Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet (either lowercase or uppercase or both). For example, we say the letter A is present in the string if either 'a' is present or 'A' is present.

Example 1:
Input:
S = Bawds jog, flick quartz, vex nymph
Output: 1
Explanation: In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.

Example 2:
Input:
S = sdfs
Output: 0
Explanation: In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.
Your Task:
 You need to complete the function checkPangram() that takes a string as a parameter and returns true if the string is a pangram, or else it returns false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
*/


class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        transform(str.begin(),str.end(),str.begin(),::tolower);
        unordered_map<char,int> mp;
        for(char i='a';i<='z';i++){
            mp[i]=1;
        }
        for(int i=0;i<str.size();i++){
            if(isalpha(str[i])){
                mp[str[i]]--;
                if(mp[str[i]]<=0) mp.erase(str[i]);
            }
        }
        // for(auto it : mp){
        //     if(it.second<=0) mp.erase(it.first);
        // }
    return mp.empty();
    }

};


/// Another Solution


class Solution {
public:
    bool checkIfPangram(string sentence){
        map<char, int> mp;
        for(int i=0; i<sentence.size();i++){
            mp[sentence[i]]++;
        }
        if(mp.size() == 26){
            return true;
        }
    return false;
    }
};
