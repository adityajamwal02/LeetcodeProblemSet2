// 3295. Report Spam Message

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords){
        unordered_set<string> st(bannedWords.begin(),bannedWords.end());
        int counter=0;
        for(auto str : message){
            if(st.find(str)!=st.end()){
                counter++;
            }
            if(counter>=2) return true;
        }
    return false;
    }
};
