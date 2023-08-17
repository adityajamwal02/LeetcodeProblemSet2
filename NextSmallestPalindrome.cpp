/*
Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:
Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
9 4 1 8 8 0 8 8 1 4 9

Example 2:
Input:
N = 5
Num[] = {2, 3, 5, 4, 5}
Output: 2 3 6 3 2
Explanation: Next smallest palindrome is
2 3 6 3 2
Your Task:
Complete the function generateNextPalindrome() which takes an array num, and a single integer n, as input parameters and returns an array of integers denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    vector<int> ans(num, num + n);
        if (n == 1)
        {
            if (num[0] == 9)
            {
                return {1, 1};
            }
            else
            {
                return {num[0] + 1};
            }
        }
         int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;
        bool leftsmaller = false;

        while (i >= 0 and j < n and ans[i] == ans[j])
        {
            i--;
            j++;
        }
        if (i < 0 or (ans[i] < ans[j]))
        {
            leftsmaller = true;
        }
        while (i >= 0)
        {
            ans[j++] = ans[i--];
        }
        if (leftsmaller)
        {
            int carry = 1;
            i = mid - 1;
            if (n % 2 == 1)
            {
                ans[mid] += carry;
                carry = ans[mid] / 10;
                ans[mid] %= 10;
                j = mid + 1;
            }
            else
            {
                j = mid;
            }
            while ((i >= 0 || carry))
            {
                if (i >= 0)
                {
                    ans[i] += carry;
                    carry = ans[i] / 10;
                    ans[i] %= 10;
                    ans[j++] = ans[i--];
                }
                else if (carry)
                {
                    ans.insert(ans.begin(), carry);
                    ans[j] = carry;
                    carry = 0;
                    i = 0;
                }
            }
        }

        return ans;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
