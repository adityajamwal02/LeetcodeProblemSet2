/*
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters.

Example 1:
Input:
S = "aba", K = 2
Output:
3
Explanation:
The substrings are:
"ab", "ba" and "aba".

Example 2:
Input:
S = "abaaca", K = 1
Output:
7
Explanation:
The substrings are:
"a", "b", "a", "aa", "a", "c", "a".

Your Task:
You don't need to read input or print anything. Your task is to complete the function substrCount() which takes the string S and an integer K as inputs and returns the number of substrings having exactly K distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).
*/


//User function template for C++

class Solution
{
  public:
      long long int helper(string s, int k){
          int hashmap[26]={0};
        	long long int counter=0;
        	int i=0, j=0, distinct=0;
        	for(j=0;j<s.size();j++){
        	    if(hashmap[s[j]-'a']==0){
        	        distinct++;
        	    }
        	    hashmap[s[j]-'a']++;
        	    while(distinct>k){
        	        hashmap[s[i]-'a']--;
        	        if(hashmap[s[i]-'a']==0) distinct--;
        	        i++;
        	    }
        	    counter+=j-i+1;
        	}
        return counter;
      }
    long long int substrCount (string s, int k) {
        return helper(s,k)-helper(s,k-1);
    }
};
