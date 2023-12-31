/*
You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
Return a list of lists of the suggested products after each character of searchWord is typed.

Example 1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

Example 2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
*/

struct Trie{
    Trie* next[26]={nullptr};
    bool end=false;
    Trie(){
        //for(int i=0;i<26;i++) next[i]=NULL;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
        Trie* root=new Trie();
        for(int i=0;i<products.size();i++){
            insert(root,products[i]);
        }
        vector<vector<string>> result;
        string temp="";
        for(int i=0;i<searchWord.size();i++){
            temp+=searchWord[i];
            result.push_back(search(root,temp));
        }
    return result;
    }

    vector<string> search(Trie *root, string temp) {
        Trie *p=root;
        vector<string> ans;
        string curr;
        for(int i=0;i<temp.size(); i++) {
            if(p->next[temp[i]-'a']==NULL) return ans;
            else{
                curr+=temp[i];
                p=p->next[temp[i]-'a'];
            }
        }
        wordSearch(p,curr,ans);
    return ans;
    }

    void wordSearch(Trie *root, string curr, vector<string> &ans){
        Trie *p=root;
        if(ans.size()==3) return;
        if(p->end) ans.push_back(curr);
        string temp;
        for(int i=0;i<26;i++){
            if(p->next[i]!=NULL){
                temp="";
                temp='a'+i;
            wordSearch(p->next[i],curr+temp,ans);
            }
        }
    }

    void insert(Trie *root, string t) {
        Trie *p=root;
        for(int i=0;i<t.size();i++) {
            if(p->next[t[i]-'a']==NULL) {
                p->next[t[i]-'a']=new Trie();
            }
            p=p->next[t[i]-'a'];
        if(i==t.size()-1) p->end=true;
        }
    }
};


