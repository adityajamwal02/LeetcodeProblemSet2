/*
Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid distinct sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:
Input:
N = 2
C = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation:
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)

Example 2:
Input:
N = 4
C = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation:
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

Expected Time Complexity: O(Klog(N))
Expected Auxiliary Space: O(N)
*/

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &a, vector<int> &b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        priority_queue<int> p;
        vector<int> res;

        for(int i = N-1;i>=N-K;i--){
            for(int j = N-1;j>=N-K;j--){
                if(p.size()<K) p.push(-(a[i]+b[j]));
                else{
                    if((a[i]+b[j])>-p.top()){
                        p.pop();
                        p.push(-(a[i]+b[j]));
                    }
                    else break;
                }
            }
        }
        while(!p.empty()){
            res.push_back(-p.top());
            p.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
