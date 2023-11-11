/*
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.
Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

Example 1:
Input: path = "NES"
Output: false
Explanation: Notice that the path doesn't cross any point more than once.

Example 2:
Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
*/

class Solution {
public:
    bool isPathCrossing(string path){
        pair<int,int> currPointer={0,0};
        set<pair<int,int>> st;
        st.insert(currPointer);
        for(int i=0;i<path.size();i++){
            if(path[i]=='N'){
                currPointer.second+=1;
            }else if(path[i]=='S'){
                currPointer.second-=1;
            }else if(path[i]=='E'){
                currPointer.first+=1;
            }else if(path[i]=='W'){
                currPointer.first-=1;
            }
            if(st.find(currPointer)!=st.end()) return true;
        st.insert(currPointer);
        }
    return false;
    }
};

