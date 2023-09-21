/// Template of Insert, search and startsWith in Trie : O(n) time complexity

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag=false;

    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node *node){
        links[ch-'a']=node;
    }

    Node *get(char ch){
        return links[ch-'a'];
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
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        if(node->isEnd()==true) return true;
    return false;
    }

    bool startsWith(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
    return true;
    }
};

