/*
Given an array A of N non-negative numbers and you are also given non-negative number B.
You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.
*/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size() , counter=0, currSum=0;
    int i=0, j=0;
    while(j<n){
        currSum+=A[j];
        if(currSum>=B){
            while(currSum>=B and i<=j){
                currSum-=A[i];
            i++;
            }
        }
        counter+=(j-i+1);
    j++;
    }
return counter;
}
