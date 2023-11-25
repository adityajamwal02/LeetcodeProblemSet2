/*
There is a grid with n + 2 horizontal bars and m + 2 vertical bars, and initially containing 1 x 1 unit cells.
The bars are 1-indexed.
You are given the two integers, n and m.
You are also given two integer arrays: hBars and vBars.
hBars contains distinct horizontal bars in the range [2, n + 1].
vBars contains distinct vertical bars in the range [2, m + 1].
You are allowed to remove bars that satisfy any of the following conditions:
If it is a horizontal bar, it must correspond to a value in hBars.
If it is a vertical bar, it must correspond to a value in vBars.
Return an integer denoting the maximum area of a square-shaped hole in the grid after removing some bars (possibly none).

Example 1:
Input: n = 2, m = 1, hBars = [2,3], vBars = [2]
Output: 4
Explanation: The left image shows the initial grid formed by the bars.
The horizontal bars are in the range [1,4], and the vertical bars are in the range [1,3].
It is allowed to remove horizontal bars [2,3] and the vertical bar [2].
One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.
The resulting grid is shown on the right.
The hole has an area of 4.
It can be shown that it is not possible to get a square hole with an area more than 4.
Hence, the answer is 4.

Example 2:
Input: n = 1, m = 1, hBars = [2], vBars = [2]
Output: 4
Explanation: The left image shows the initial grid formed by the bars.
The horizontal bars are in the range [1,3], and the vertical bars are in the range [1,3].
It is allowed to remove the horizontal bar [2] and the vertical bar [2].
To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.
The resulting grid is shown on the right.
The hole has an area of 4.
Hence, the answer is 4, and it is the maximum possible.

Example 3:
Input: n = 2, m = 3, hBars = [2,3], vBars = [2,3,4]
Output: 9
Explanation: The left image shows the initial grid formed by the bars.
The horizontal bars are in the range [1,4], and the vertical bars are in the range [1,5].
It is allowed to remove horizontal bars [2,3] and vertical bars [2,3,4].
One way to get the maximum square-shaped hole is by removing horizontal bars 2 and 3, and vertical bars 3 and 4.
The resulting grid is shown on the right.
The hole has an area of 9.
It can be shown that it is not possible to get a square hole with an area more than 9.
Hence, the answer is 9.
*/

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars){
        int result=0, prev=0, curr=0, result2=0, curr2=0, prev2=0, ans;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i=0;i<hBars.size();i++){
            if(hBars[i]==prev+1){
                prev=hBars[i];
                curr++;
            }else if(i==0){
                curr=1, prev=hBars[i];
                result=max(result,curr);
            }else{
                result=max(result,curr);
                curr=1, prev=hBars[i];
            }
        }
        result=max(result,curr);
        for(int i=0;i<vBars.size();i++){
            if(vBars[i]==prev2+1){
                prev2=vBars[i];
                curr2++;
            }else if(i==0){
                curr2=1, prev2=vBars[i];
                result2=max(result2,curr2);
            }else{
                result2=max(result2,curr2);
                curr2=1, prev2=vBars[i];
            }
        }
        result2=max(result2,curr2);
        ans=min(result,result2);
        int res=pow(ans+1,2);
    return res;
    }
};

