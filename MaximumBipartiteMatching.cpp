/*
There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interseted in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Given a matrix G where G(i,j) denotes ith applicant is interested in jth job. Find an assignment of jobs to applicant in such that as many applicants as possible get jobs.

Example 1:
Input: G = {{1,1,0,1,1},{0,1,0,0,1},
{1,1,0,1,1}}
Output: 3
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.
Third applicant gets the 3rd job.

Example 2:
Input: G = {{1,1},{0,1},{0,1},{0,1},
{0,1},{1,0}}
Output: 2
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.

Your Task:
You don't need to read to print anything. Your task is to complete the function maximumMatch() which takes matrix G as input parameter and returns the maximum number of applicants who can get the job.

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N)
*/

class Solution {
public:
    int dfs(int i, vector<int> &matchjobs, vector<int> &seen, vector<vector<int>> &G, int n, int m){
        for(int j=0;j<n;j++){
            if(G[i][j] and !seen[j]){
                seen[j]=true;
                if(matchjobs[j]==-1 or dfs(matchjobs[j],matchjobs,seen,G,n,m)){
                    matchjobs[j]=i;
                    return true;
                }
            }
        }
    return false;
    }
	int maximumMatch(vector<vector<int>>&G){
	    int n=G[0].size(), m=G.size();
	    vector<int> matchjobs(n,-1);
	    int counter=0;
	    for(int i=0;i<m;i++){
	        vector<int> seen(n,0);
	        if(dfs(i,matchjobs,seen,G,n,m)) counter++;
	    }
	    return counter;
	}

};
