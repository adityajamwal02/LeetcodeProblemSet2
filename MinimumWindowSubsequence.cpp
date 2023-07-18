/*
Given strings str1 and str2, find the minimum (contiguous) substring W of str1, so that str2 is a subsequence of W.
If there is no such window in str1 that covers all characters in str2, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:
Input:
str1: geeksforgeeks
str2: eksrg
Output:
eksforg
Explanation:
Eksforg satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.

Example 2:
Input:
str1: abcdebdde
str2: bde
Output:
bcde
Explanation:
"bcde" is the answer and "deb" is not a smaller window because the elements of T in the window must occur in order.
Your Task:

Complete the function string minWindow(string str1, string str2), which takes two strings as input and returns the required valid string as output.
*/


string minWindow(string S, string T)
{
	/// Minimum substring W of S such that T is a subsequence of W
	// abcdebdde -> S and T=bde : Then Result= bcde (4)
	int i=0,j=0,k=0,minLen=INT_MAX;
	int n=S.size(), m=T.size();
	string result;
	while(j<n and k<m){
		if(S[j]==T[k]){
			k++;
		}
		if(k==m){
			i=j;
			k=m-1;
			while(i>=0 and k>=0){
				if(S[i]==T[k]){
					k--;
				}
			i--;
			}
			i++;
			if(minLen>(j-i+1)){
				minLen=j-i+1;
				result=S.substr(i,minLen);
			}
			k=0,j=i+1;				// Start from very next of i (for any more lesser window subsequence)
		}
	j++;
	}
	return result;
}
