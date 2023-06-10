/*
You are given a 0-indexed string s that consists of digits from 0 to 9.
A string t is called a semi-repetitive if there is at most one consecutive pair of the same digits inside t.
Return the length of the longest semi-repetitive substring inside s.
A substring is a contiguous non-empty sequence of characters within a string.

Example 1:
Input: s = "52233"
Output: 4
Explanation: The longest semi-repetitive substring is "5223", which starts at i = 0 and ends at j = 3.

Example 2:
Input: s = "5494"
Output: 4
Explanation: s is a semi-reptitive string, so the answer is 4.

Example 3:
Input: s = "1111111"
Output: 2
Explanation: The longest semi-repetitive substring is "11", which starts at i = 0 and ends at j = 1.
*/

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
      int i = 0;
    int length = s.length();
    int j = length;

    deque<char> st;
    int oneDupli = 0;
    int maxLen = 0;

    for (int k = 0; k < length; k++) {
        char c = s[k];
        if (st.size() == 0) {
            st.push_back(c);
        } else {
            char top = st.back();
            if (top == c) {
                if (oneDupli == 0) {
                    st.push_back(c);
                    if (st.size() > maxLen)
                        maxLen = st.size();
                    oneDupli = 1;
                } else {
                    int size = st.size();
                    if (size > maxLen)
                        maxLen = size;
                    st.push_back(c);
                    char prev = st.front();
                    st.pop_front();
                    while (st.size() > 0) {
                        char next = st.front();
                        if (prev == next) {
                            break;
                        } else {
                            prev = st.front();
                            st.pop_front();
                        }
                    }
                }
            } else {
                st.push_back(c);
                if (st.size() > maxLen)
                    maxLen = st.size();
            }
        }
    }

    if (st.size() > maxLen)
        maxLen = st.size();

    return maxLen;
    }
};
