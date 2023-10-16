/*
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

Example 2:
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
*/

lass Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary){
        sort(dictionary.begin(),dictionary.end(),[&](string &s1, string &s2){
            if(s1.size()==s2.size()) return s1>s2;
        return s1.size()<s2.size();
        });
        int n=s.size(), maxSize=INT_MIN;
        string result="#";
        for(auto word : dictionary){
            int i=0, j=0, m=word.size();
            while(i<n and j<m){
                if(s[i]==word[j]){
                    i++;
                    j++;
                }else{
                    i++;
                }
            }
            if(j==m){
                if(maxSize<m){
                    result=word;
                }
            }
        }
    return (result=="#") ? "" : result;
    }
};
