/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

Example 1:
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: tiles = "AAABBC"
Output: 188

Example 3:
Input: tiles = "V"
Output: 1
*/

class Solution {
public:
    void helper(int n, string temp, string tiles, unordered_set<string> &st, vector<bool> &vis){
        st.insert(temp);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                helper(n,temp+tiles[i],tiles,st,vis);
                vis[i]=false;
            }
        }
    }

    int numTilePossibilities(string tiles){
        int n=tiles.size();
        unordered_set<string> st;
        vector<bool> vis(n,false);
        helper(n,"",tiles,st,vis);

    return st.size()-1;
    }
};
