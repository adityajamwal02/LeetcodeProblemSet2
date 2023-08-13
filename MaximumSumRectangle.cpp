/*
Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
Thumbnail
Example 2:

Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
Explanation:
Taking only the first cell is the
optimal choice.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maximumSumRectangle() which takes the number R, C, and the 2D matrix M as input parameters and returns the maximum sum submatrix.


*/


class Solution {
  public:
    long long maxSum=INT_MIN;

    void kadane(vector<int> &arr, int n){
    	long long currSum=0;
    	for(int i=0;i<n;i++){
    		currSum+=arr[i];
    		maxSum=max(maxSum,currSum);
    		if(currSum<=0) currSum=0;
    	}
    }

    int maximumSumRectangle(int n, int m, vector<vector<int>> arr) {
        for(int k=0;k<m;k++){
		vector<int> nums(n,0);
		for(int j=k;j<m;j++){
			for(int i=0;i<n;i++){
				nums[i]+=arr[i][j];
			}
			kadane(nums,n);
		}
	}
	return maxSum;
    }
};
