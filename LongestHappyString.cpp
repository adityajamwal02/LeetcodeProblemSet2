/*
A string s is called happy if it satisfies the following conditions:
s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string result="";
        char prev;
        int lastCount=0;
        while(!pq.empty()){
            pair<int,char> topPair=pq.top();
            pq.pop();
            if(topPair.second==prev and lastCount==2){
                pair<int,char> nextPair=topPair;
                if(pq.empty()) return result;
                topPair=pq.top();
                pq.pop();
                pq.push(nextPair);
            }
            topPair.first--;
            result.push_back(topPair.second);
            if(topPair.second==prev){
                lastCount++;
            }else{
                lastCount=1;
                prev=topPair.second;
            }
            if(topPair.first>0){
                pq.push(topPair);
            }
        }
    return result;
    }
};
