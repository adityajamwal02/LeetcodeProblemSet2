/*
Given a string licensePlate and an array of strings words, find the shortest completing word in words.
A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.
For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".
Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
Output: "steps"
Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
"step" contains 't' and 'p', but only contains 1 's'.
"steps" contains 't', 'p', and both 's' characters.
"stripe" is missing an 's'.
"stepple" is missing an 's'.
Since "steps" is the only word containing all the letters, that is the answer.

Example 2:
Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
Output: "pest"
Explanation: licensePlate only contains the letter 's'. All the words contain 's', but among these "pest", "stew", and "show" are shortest. The answer is "pest" because it is the word that appears earliest of the 3.
*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
        unordered_map<char, int> mp;
        for (int i = 0; i < licensePlate.size(); i++) {
            if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z') {
                mp[licensePlate[i]]++;
            }
        }
        int index = -1, mini = INT_MAX;
        string result;
        for (auto word : words) {
            int n = word.size();
            unordered_map<char, int> ump;
            for (int i = 0; i < n; i++) {
                ump[word[i]]++;
            }
            bool flag = true;
            for (auto it1 : mp) {
                if (ump.find(it1.first) == ump.end() || ump[it1.first] < it1.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (mini > n) {
                    mini = n;
                    result = word;
                }
            }
        }
        return result;
    }
};
