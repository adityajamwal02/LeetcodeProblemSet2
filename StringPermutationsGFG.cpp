/*
Given a string S. The task is to find all permutations (need not be different) of a given string.

Example 1:

Input:
S = AAA
Output: AAA AAA AAA AAA AAA AAA
Explanation: There are total 6 permutations, as given in the output.
Example 2:

Input:
S = ABSG
Output: ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA GABS
GASB GBAS GBSA GSAB GSBA SABG SAGB
SBAG SBGA SGAB SGBA
Explanation: There are total 24 permutations, as given in the output.
*/

 void solve(int index, string &s, vector<string> &result){
        if(index>=s.size()){
            result.push_back(s);
            return;
        }
        for(int i=index;i<s.size();i++){
            swap(s[i],s[index]);
            solve(index+1,s,result);
            swap(s[i],s[index]);
        }
    }

    vector<string> permutation(string S)
    {
        vector<string> result;
        int i=0;
        solve(i,S,result);
        sort(result.begin(),result.end());
    return result;
    }
};
