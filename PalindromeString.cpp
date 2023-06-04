/*
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc"
Output: 0
Explanation: S is not a palindrome


Your Task:
You don't need to read input or print anything. Complete the function isPalindrome()which accepts string S and returns an integer value 1 or 0.

Expected Time Complexity: O(Length of S)
Expected Auxiliary Space: O(1)
*/


/// Recursive Solution

bool isPalindrome(string s, int start, int end) {
    // Base case: If the start and end pointers meet or cross each other, it's a palindrome
    if (start >= end)
        return true;

    // Recursive case: Check if characters at start and end positions are equal
    if (s[start] != s[end])
        return false;

    // Recursively check the remaining substring
    return isPalindrome(s, start + 1, end - 1);
}

int isPalindrome(string s) {
    int length = s.length();
    if (length <= 1)
        return 1;  // A single character or empty string is considered a palindrome

    return isPalindrome(s, 0, length - 1) ? 1 : 0;
}


/// String based palindrome check


	int isPalindrome(string S)
	{
	    int n=S.size(), i=0, j=n-1;
	    while(i<j){
	        if(S[i]!=S[j]) return 0;
	        else{
	            i++;
	            j--;
	        }
	    }
	   return 1;
	}

};
