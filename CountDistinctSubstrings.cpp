/*
Given a string of length N of lowercase alphabet characters. The task is to complete the function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case in a new line, output will be an integer denoting count of total number of distinct substrings of this string.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function countDistinctSubstring().

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 1000

Example(To be used only for expected output):
Input:
2
ab
ababa

Output:
4
10

Exaplanation:
Testcase 1: For the given string "ab" the total distinct substrings are: "", "a", "b", "ab".
*/

struct Node{
    Node *links[26];

    bool containsKey(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node *node){
        links[ch-'a']=node;
    }

    Node *get(char ch){
        return links[ch-'a'];
    }

};


int countDistinctSubstring(string s){
    int n=s.size(), counter=0;
    Node *root=new Node();
    for(int i=0;i<n;i++){
        Node *node=root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j])){
                counter++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
return counter+1;
}
