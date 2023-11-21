/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.
*/

class Solution {
public:
    char next(char ch){
        if(ch=='9') return '0';
    return ch+1;
    }

    char prev(char ch){
        if(ch=='0') return '9';
    return ch-1;
    }

    int openLock(vector<string>& deadends, string target){
        unordered_set<string> st{deadends.begin(),deadends.end()};
        string root="0000";
        queue<string> q;
        q.push(root);
        if(st.count(root)) return -1;
        if(root==target) return 0;
        int level=0;
        for(int level=0,sz=1;!q.empty();level++,sz=q.size()){
            while(sz--){
                string cur = q.front();
                q.pop();

                for(int i = 0 ; i < 4 ; i++){
                    cur[i] = next(cur[i]);
                    if(cur == target) return level + 1;

                    if(st.insert(cur).second)
                      q.push(cur);

                    cur[i] = prev(prev(cur[i]));
                    if(cur == target) return level + 1;
                    if(st.insert(cur).second)
                      q.push(cur);

                    cur[i]=next(cur[i]);
                }
            }
        }
    return -1;
    }
};
