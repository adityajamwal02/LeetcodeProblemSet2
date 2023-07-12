/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
*/

/// To avoid large cases TLE, pass result by reference rather than global declaration

class Solution {
public:
    vector<vector<int>> result;
    // index -> (1...), n->sum
    void helper(int index, int n, int k, vector<int> temp){
        if(n==0 and k==0){
            result.push_back(temp);
            return;
        }
        for(int i=index;i<=9;i++){
            temp.push_back(i);
            helper(i+1,n-i,k-1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n<k) return result;
        vector<int> temp;
        helper(1,n,k,temp);
    return result;
    }
};
