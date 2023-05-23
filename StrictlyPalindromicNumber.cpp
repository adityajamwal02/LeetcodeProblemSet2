/*
An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), the string representation of the integer n in base b is palindromic.
Given an integer n, return true if n is strictly palindromic and false otherwise.
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.

Example 2:
Input: n = 4
Output: false
Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.
*/

/// Brainteaser Solution --> Reason:

/// The reason behind is that when we convert any number n in it's (n-2) base then it will always give 12 which is not palindromic.
/// So there is no such number which is palindromic..

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};


/// Another Solution

class Solution
{
public:
	bool isStrictlyPalindromic(int n)
	{
		vector<int> arr;
		int temp, j;
		for (int i = 2; i < n - 1; i++)
		{
			temp = n;
			while (temp)
			{
				arr.push_back(temp % i);
				temp = temp / i;
			}
			int x = 0;
			j = arr.size();
			while (x < j)
			{
				if (arr[x] != arr[j - x - 1])
					return false;
				x++;
			}
			arr.clear();
		}
		return true;
	}
};
