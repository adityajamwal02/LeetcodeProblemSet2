/// Largest Subarray Sum Minimized OR Split Array Largest Sum


bool isValid(vector<int> &a, int k, int mid){
    int n=a.size(), pieces=1, currSum=0;
    for(int i=0;i<n;i++){
        if(currSum+a[i]<mid){
            currSum+=a[i];
        }else{
            currSum=a[i];
            pieces++;
        }
    }
return pieces>k;
}


int largestSubarraySumMinimized(vector<int> a, int k) {
    // min of max
    int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);
    int result=low;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isValid(a,k,mid)){
            result=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
return result;
}
