/*
Design a map that allows you to do the following:
Maps a string key to a given value.
Returns the sum of the values that have a key with a prefix equal to a given string.
Implement the MapSum class:
MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
*/

/// Designing Map : Brute Approach

class MapSum {
public:
    unordered_map<string,int> mp;

    MapSum(){
    }

    void insert(string key, int val){
        mp[key]=val;
    }

    int sum(string prefix){
        int result=0, n=prefix.size();
        for(auto it : mp){
            int i=0, j=0;
            string temp=it.first;
            while(i<n and j<n){
                if(prefix[i]!=temp[j]) break;
                else{
                    i++;
                    j++;
                }
            }
            if(i==n) result+=it.second;
        }
    return result;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */


/// Trie Approach



