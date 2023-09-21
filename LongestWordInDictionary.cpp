/*
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
Note that the word should be built from left to right with each additional character being added to the end of a previous word.

Example 1:
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
*/

struct Node{
    Node *links[26];
    bool flag=false;
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node *node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node *root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
        node=node->get(word[i]);
        }
    node->setEnd();
    }
    bool checkIfPrefixExists(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node=node->get(word[i]);
                if(node->isEnd()==false) return false;
            }
            else return false;
        }
    return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words){
        string longest="";
        Trie trie;
        for(auto str : words){
            trie.insert(str);
        }
        for(auto str : words){
            if(trie.checkIfPrefixExists(str)){
                if(str.size()>longest.size()){
                    longest=str;
                }else if(str.size()==longest.size() and str<longest){
                    longest=str;
                }
            }
        }
    return longest;
    }
};
