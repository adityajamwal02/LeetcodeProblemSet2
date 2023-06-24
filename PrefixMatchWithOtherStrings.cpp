/*
Given an array of strings arr[] of size n, a string str and an integer k. The task is to find the count of strings in arr[] whose prefix of length k matches with the k-length prefix of str.

Example 1:
Input:
n = 6
arr[] = {“abba”, “abbb”, “abbc”, “abbd”,
“abaa”, “abca”}
str = “abbg”
k = 3
Output:
4
Explanation:
“abba”, “abbb”, “abbc” and “abbd” have their prefix of length 3 equal to 3-length prefix of str i.e., "abb".

Example 2:
Input:
n = 3
arr[] = {“geeks”, “geeksforgeeks”, “forgeeks”}
str = “geeks”
k = 2
Output:
2
Explanation:
“geeks” and “geeksforgeeks” have their prefix of length 2 equal to 2-length prefix of str i.e., "ge".
Your Task:
You don't need to read input or print anything. Your task is to complete the function klengthpref() which takes the array of strings arr[], its size n and an integer k, a string str as input parameters and returns the count of strings in arr[] whose prefix of length k matches with the k length prefix of str.

Expected Time Complexity: O(n*l) where l is the length of the longest word in arr[].
Expected Auxiliary Space: O(n*l) where l is the length of the longest word in arr[].

Constraints:
1 <= n <= 1000
1 <= |arr[i]| , |str| <= 1000
1 <= k <= 1000
arr[i], str must contain only lowercase English alphabets
*/

/// Logical Solution

class Solution{
public:
    int klengthpref(string arr[], int n, int k, string str){
        int counter=0;
        int sz=str.size();
        if(k>sz) return 0;
        string check=str.substr(0,k);
        for(int i=0;i<n;i++){
            string temp=arr[i].substr(0,k);
            if(temp==check) counter++;
        }
    return counter;
    }
};

/// Optimal Solution : Trie (Time Complexity: O(n*l) Space Complexity: O(m*l) m-> no of unique characters present in strings l -> length of longest string present in the array

 struct Node{
    int pre_cnt;
    unordered_map<char,Node*>next;
    Node(){
        pre_cnt=0;
    }
};

int klengthpref(string a[], int n, int k, string s){
    if(s.length()<k)return 0;
    Node* root = new Node();
    int i,j,cnt=0;
    for(i=0;i<n;i++){
        string x=a[i];
        Node *temp=root;
        for(j=0;j<x.length();j++){
            if(temp->next.find(x[j])==temp->next.end())temp->next[x[j]]=new Node();
            temp=temp->next[x[j]];
            temp->pre_cnt++;
        }
    }
    Node *temp=root;
    for(i=0;i<k;i++){
        if(temp->next.find(s[i])==temp->next.end())return 0;
        else temp=temp->next[s[i]];
    }
    return temp->pre_cnt;
}
