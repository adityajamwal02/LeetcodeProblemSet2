/*
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.

Example 2:
Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".

Example 3:
Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s){
        int result=INT_MIN;
        unordered_map<char,pair<int,int>> mp;
        mp[s[0]].first=0;
        for(auto ch : s){
            mp[ch]={-1,-1};
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]].first==-1) mp[s[i]].first=i;
            else mp[s[i]].second=i;
        }
        for(auto pair : mp){
            int start=pair.second.first, end=pair.second.second;
            if(end<=start) continue;
            result=max(result,end-start-1);
        }
    return result==INT_MIN ? -1 : result;
    }
};
