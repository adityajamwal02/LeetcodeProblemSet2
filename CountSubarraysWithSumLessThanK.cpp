/// Count subarrays with sum (window sum) is less than k : Sliding window Approach

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

