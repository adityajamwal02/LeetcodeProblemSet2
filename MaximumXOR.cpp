/// Coding ninjas : Tries + Bit Manipulation

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node *get(int bit){
        return links[bit];
    }

    void put(int bit, Node *node){
        links[bit]=node;
    }
};

class Trie{
        Node *root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node *node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
            node=node->get(bit);
            }
        }

        int getMax(int num){
            Node *node=root;
            int maxNum=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->containsKey(1-bit)){
                    maxNum=maxNum|(1<<i);
                    node=node->get(1-bit);
                }else{
                    node=node->get(bit);
                }
            }
        return maxNum;
        }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for(auto it : arr1){
        trie.insert(it);
    }
    int maxVal=0;
    for(auto it : arr2){
        maxVal=max(maxVal,trie.getMax(it));
    }
return maxVal;
}
