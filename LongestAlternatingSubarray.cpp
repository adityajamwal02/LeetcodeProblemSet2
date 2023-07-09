/*
You are given a 0-indexed integer array nums. A subarray s of length m is called alternating if:

m is greater than 1.
s1 = s0 + 1.
The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In other words, s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and so on up to s[m - 1] - s[m - 2] = (-1)m.
Return the maximum length of all alternating subarrays present in nums or -1 if no such subarray exists.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [2,3,4,3,4]
Output: 4
Explanation: The alternating subarrays are [3, 4], [3, 4, 3], and [3, 4, 3, 4]. The longest of these is [3,4,3,4], which is of length 4.

Example 2:
Input: nums = [4,5,6]
Output: 2
Explanation: [4,5] and [5,6] are the only two alternating subarrays. They are both of length 2.
*/

/// Stack Based Approach

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int LengthSize = nums.size();
        vector<int> temp;
        for (int i = 1; i < LengthSize; i++) {
            temp.push_back(nums[i] - nums[i - 1]);
        }

        int max = 0;
        stack<int> st;

        for (int i = 0; i < temp.size(); i++) {
            int value = temp[i];
            if (st.empty() && value == 1) {
                st.push(value);
                if (1 > max)
                    max = 1;
            }
            else if (!st.empty()) {
                int top = st.top();
                if (value == 1) {
                    if (top == -1) {
                        st.push(1);
                        if (st.size() > max)
                            max = st.size();
                    }
                    else {
                        if (st.size() > max)
                            max = st.size();
                        st = stack<int>();
                        st.push(1);
                        if (1 > max)
                            max = 1;
                    }
                }
                else if (value == -1) {
                    if (top == 1) {
                        st.push(-1);
                        if (st.size() > max)
                            max = st.size();
                    }
                    else {
                        st = stack<int>();
                    }
                }
                else {
                    if (st.size() > max)
                        max = st.size();
                    st = stack<int>();
                }
            }
        }

        if (max > 0)
            return max + 1;
        else
            return -1;

    }
};


