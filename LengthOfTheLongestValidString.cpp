/*
You are given a string word and an array of strings forbidden.
A string is called valid if none of its substrings are present in forbidden.
Return the length of the longest valid substring of the string word.
A substring is a contiguous sequence of characters in a string, possibly empty.

Example 1:
Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
Output: 4
Explanation: There are 9 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", and "aabc". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "aaa" or "cb" as a substring.

Example 2:
Input: word = "leetcode", forbidden = ["de","le","e"]
Output: 4
Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "de", "le", or "e" as a substring.
*/

/// Sliding Window Solution

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> st(forbidden.begin(),forbidden.end());
        int i=-1, j=0, result=0, n=word.size();
        string curr="";
        while(j<n){
            curr+=word[j];
            string str="";
            for(int k=j;k>(j-10);k--){
                if(k<=i) break;
                str=word[k]+str;
                if(st.find(str)!=st.end()){
                    curr="";
                    i=k;
                    for(int l=k+1;l<=min(j,n-1);l++){
                        curr+=word[l];
                    }
                    break;
                }
            }
            int length=curr.size();
            result=max(result,length);
        j++;
        }
    return result;
    }
};

/// Trie


class Solution {
public:
    struct Node{
        Node* child[26];
        bool isTerminal;

        Node(){
            isTerminal=false;
            for(int i=0;i<26;i++)  child[i]=NULL;
        }
    };

    Node* root=new Node();

    // insert all the forbiddens
    void insert(string &s){
        int n=s.size();
        Node* curr=root;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';

            if(curr->child[idx]==NULL){
                curr->child[idx]=new Node();
            }

            curr=curr->child[idx];
        }

        curr->isTerminal=true;
    }

    //search if any forbiddens present starting with word[l]
    bool search(string& word,int l,int r){
        Node* curr=root;
        for(;l<=r;l++){
            int idx=word[l]-'a';
            if(curr->child[idx]==NULL) return false;
            curr=curr->child[idx];
            if(curr->isTerminal==true) return true;
        }
        return false;
    }

    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n=word.length();
        //(Trie Data Structure)
        for(auto &words : forbidden) insert(words);

        int ans=0;
        int j=n-1;
        for(int i=n-1;i>=0;i--){
            while(i<=j && search(word,i,j)) j--;
            ans=max(ans,j-i+1);
        }

        return ans;
    }
};
