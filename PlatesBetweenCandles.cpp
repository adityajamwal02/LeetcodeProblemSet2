/*
There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.
You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.
For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.

Example 1:
ex-1
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.

Example 2:
ex-2
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
*/

class Solution {
public:
    int firstOcc(int left, int right, vector<int> &candles){
        int low=0, high=candles.size()-1, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(candles[mid]<left) low=mid+1;
            else{
                if(candles[mid]<=right) ans=mid;
                high=mid-1;
            }
        }
    return ans;
    }

    int lastOcc(int left, int right, vector<int> &candles){
        int low=0, high=candles.size()-1, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(candles[mid]>right) high=mid-1;
            else{
                if(candles[mid]>=left) ans=mid;
                low=mid+1;
            }
        }
    return ans;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries){
        int n=s.size(), counter=0;
        vector<int> candles, result, prefixSum(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='|') candles.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(s[i]=='*') counter++;
            prefixSum[i]=counter;
        }
        for(auto q : queries){
            int left=firstOcc(q[0],q[1],candles);
            int right=lastOcc(q[0],q[1],candles);
            if(left==-1 or right==-1) result.push_back(0);
            else result.push_back(prefixSum[candles[right]]-prefixSum[candles[left]]);
        }
    return result;
    }
};
