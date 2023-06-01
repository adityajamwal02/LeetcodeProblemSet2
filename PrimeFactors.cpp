/*
Given a number N. Find its unique prime factors in increasing order.

Example 1:
Input: N = 100
Output: 2 5
Explanation: 2 and 5 are the unique prime
factors of 100.

Example 2:
Input: N = 35
Output: 5 7
Explanation: 5 and 7 are the unique prime
factors of 35.

Your Task:
You don't need to read or print anything. Your task is to complete the function AllPrimeFactors() which takes N as input parameter and returns a list of all unique prime factors of N in increasing order.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
*/



class Solution{
	public:
	bool isPrime(int n){
	    if(n==2) return true;
	    if(n==3) return true;
	    for(int i=2;i<n;i++){
	        if(n%i==0) return false;
	    }
	return true;
	}
	vector<int>AllPrimeFactors(int N) {
	    vector<int> result;
	    for(int i=2;i<=N;i++){
	        if(N%i==0 and isPrime(i)){
	            result.push_back(i);
	        }
	    }
	   return result;
	}
};
