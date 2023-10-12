/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Constraints:
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence){
        int n=sentence.size(),m=dictionary.size();
        unordered_map<string,int> mp;
        for(int i=0;i<m;i++){
            mp[dictionary[i]]++;
        }
        string result="", temp="";
        for(int i=0;i<n;i++){
            if(sentence[i]!=' '){
                temp+=sentence[i];
                if(mp.find(temp)!=mp.end()){
                    while(sentence[i]!=' ' and i<n) i++;
                }
            }
            if(sentence[i]==' '){
                result+=temp;
                result+=' ';
                temp="";
            }
        }
        result+=temp;
    return result;
    }
};

