/*
You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
Return the minimum number of different frogs to finish all the croaks in the given string.
A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.

Example 1:
Input: croakOfFrogs = "croakcroak"
Output: 1
Explanation: One frog yelling "croak" twice.

Example 2:
Input: croakOfFrogs = "crcoakroak"
Output: 2
Explanation: The minimum number of frogs is two.
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

Example 3:
Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.
*/

class Solution {
public:
    int minNumberOfFrogs(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(mp['r']>mp['c'] or mp['o']>mp['c'] or mp['a']>mp['c'] or mp['k']>mp['c'] or
                mp['r']<mp['o'] or mp['r']<mp['a'] or mp['r']<mp['k'] or
                    mp['o']<mp['a'] or mp['o']<mp['k'] or mp['a']<mp['k']){ return -1; }
        }
        int x=mp[s[0]];
        for(auto it : mp){
            if(mp[it.first]!=x){
                return -1;
            }
        }
        int counter=0, vval=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='c'){
                vval++;
            }else if(s[i]=='k'){
                vval--;
            }
            counter=max(counter,vval);
        }
    return counter;
    }
};
