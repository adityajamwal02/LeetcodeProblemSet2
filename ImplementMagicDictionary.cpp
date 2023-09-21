/*
Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.
Implement the MagicDictionary class:
MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.

Example 1:
Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False
*/

class MagicDictionary {
public:
    vector<string> dict;

    MagicDictionary(){
    }

    void buildDict(vector<string> dictionary) {
        for(auto str : dictionary){
            dict.push_back(str);
        }
    }

    bool search(string searchWord) {
        for(auto temp : dict){
            for(int j=0;j<temp.size();j++){
                if(temp[j]==searchWord[j]) continue;
                else{
                    temp[j]=searchWord[j];
                    if(temp==searchWord){
                        return true;
                    }
                break;
                }
            }
        }
    return false;
    }
};
