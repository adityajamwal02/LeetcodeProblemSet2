/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Example 1:
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

Example 2:
Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3

Constraints:
1 <= dominoes.length <= 4 * 104
dominoes[i].length == 2
1 <= dominoes[i][j] <= 9
*/

/// Brute (TLE)

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes){
        int counter=0, n=dominoes.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=dominoes[i][0], b=dominoes[i][1];
                int c=dominoes[j][0], d=dominoes[j][1];
                if((a==c and b==d) or (a==d and b==c)){
                    counter++;
                }
            }
        }
    return counter;
    }
};

/// Accepted Solution

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes){
        int counter=0;
        map<int,int> mp;
        for(auto num : dominoes){
            int value=min(num[0],num[1])*10 + max(num[0],num[1]);
            mp[value]++;
        }
        for(auto it : mp){
            counter+=(it.second*(it.second-1))/2;
        }
    return counter;
    }
};


