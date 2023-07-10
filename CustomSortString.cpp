/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.

Example 1:
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input: order = "cbafg", s = "abcd"
Output: "cbad"
*/

class Solution {
public:
    string customSortString(string order, string s) {
        // Idea : Assigning ranks based on order : mapping them all
        vector<pair<int,char>> index;
        unordered_map<char,int> mp;
        string result="";
        for(int i=0;i<order.size();i++){
            index.push_back({i,order[i]});      // {{0,c},{1,b},{2,a},{3,f},{4,g}} -> Second Sample Test case
        }
        for(int i=0;i<s.size();i++){            // Frequency of all present in string s
            mp[s[i]]++;
        }
        for(int i=0;i<index.size();i++){
            char ch=index[i].second;
            if(mp.find(ch)!=mp.end()){
                int frequency=mp[ch];
                for(int i=0;i<frequency;i++){
                    result+=ch;
                }
                mp.erase(ch);
            }
        }
        for(auto it : mp){
            int frequency=it.second;
            for(int i=0;i<frequency;i++){
                result+=it.first;
            }
        }
    return result;
    }
};
