

class Solution{
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=0, high=0;
        for(int i=0;i<R;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int counter=0;
            for(int i=0;i<R;i++){
                counter+=upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }
            if(counter<(R*C+1)/2){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return low;
    }
};
