/*
Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.
You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.
Return an integer array answer, where each answer[i] is the answer to the ith query.

Example 1:
Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Example 2:
Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
*/

class Solution {
public:
    int helper(string str){
        char mini=str[0];
        for(int i=0;i<str.size();i++){
            if(mini>str[i]){
                mini=str[i];
            }
        }
        int counter=0;
        for(int i=0;i<str.size();i++){
            if(str[i]==mini){
                counter++;
            }
        }
    return counter;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words){
        vector<int> computed, result;
        int counter=0;
        for(auto word : words){
            int currCount=helper(word);
            computed.push_back(currCount);
        }
        for(auto query : queries){
            int temp=helper(query);
            counter=0;
            for(int i=0;i<computed.size();i++){
                if(temp<computed[i]){
                    counter++;
                }
            }
        result.push_back(counter);
        }
    return result;
    }
};
