/*
You are given the string S . Compress the string when lower and upper cases are the same. In compressed string characters should be in lowercase.

Example 1:
Input: S = "aaABBb"
Output: "3a3b"
Explanation: As 'a' appears 3 times
consecutively and 'b' also 3 times,
and 'b' and 'B' considered as same.
​

Example 2:
Input: S = "aaacca"
Output: "3a2c1a"
Explanation: As 'a' appears 3 times
consecutively and 'c' also 2 times,
and then 'a' 1 time.
Your Task:
You don't need to read input or print anything. Your task is to complete the function transform() which takes the string S as inputs and returns the compressed string.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)
*/


string transform(string S){
    int counter=1;
    string result="";
    for(int i=0;i<S.size();i++){
        if(tolower(S[i])==tolower(S[i+1])) counter++;
        else{
            result+=to_string(counter);
            result+=tolower(S[i]);
            counter=1;
        }
    }
    return result;
}

/// Stack

#include <string>
#include <stack>
using namespace std;

string transform(string S) {
    stack<pair<char, int>> st;
    string compressedString = "";
    for (int i = 0; i < S.length(); i++) {
        char currentChar = tolower(S[i]);
        if (!st.empty() && currentChar == st.top().first) {
            st.top().second++;
        } else {
            st.push(make_pair(currentChar, 1));
        }
    }
    while (!st.empty()) {
        compressedString = to_string(st.top().second) + st.top().first + compressedString;
        st.pop();
    }
    return compressedString;
}

