/// Lexicographic Sorted Subsequences whose sum is equal to K (sum)

class Solution {
public:
    vector<vector<int>> result;

    void solve(int i, vector<int> &a, int n, vector<int> temp, int target){
        if(i==n){
            int sum=accumulate(temp.begin(),temp.end(),0);
            if(sum==target){
                result.push_back(temp);
            }
        return;
        }
        solve(i+1,a,n,temp,target);
        int ele=a[i];
        temp.push_back(ele);
        solve(i+1,a,n,temp,target);
    }

    vector<vector<int>> SubSequences(vector<int>&a,int K) {
        int n=a.size();
        vector<int> temp;
        solve(0,a,n,temp,K);
        sort(result.begin(),result.end());
    return result;
    }
};
