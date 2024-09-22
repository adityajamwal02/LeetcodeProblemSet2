// 3297. Count Substrings That Can Be Rearranged to Contain a String I

class Solution {
public:
    long long validSubstringCount(string word1, string word2){
        vector<int> mp(26,0);
        int counter=0;
        for(auto ch : word2){
            if(mp[ch-'a']==0) counter++;    // unique char in word2
            mp[ch-'a']++;                   // freq map
        }
        long long j=0, result=0;
        for(long long i=0;i<word1.size();i++){
            if(--mp[word1[i]-'a']==0){
                counter--;
            }
            while(counter==0){
                result+=(word1.size()-i);
                if(++mp[word1[j]-'a']==1){
                    counter++;
                }
            j++;
            }
        }
    return result;        
    }
};
