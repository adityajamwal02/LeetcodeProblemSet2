/// Given a string str and an integer k, return the number of substrings where the number of different substrings is at most k distinct characters


#include<bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
    int i=0, j=0, result=0;
    unordered_map<char,int> mp;
    while(j<str.size()){
        mp[str[j]]++;
        if(mp.size()>k){
            while(mp.size()>k){
                mp[str[i]]--;
                if(mp[str[i]]==0){
                    mp.erase(str[i]);
                }
            i++;
            }
        }
    result=max(result,j-i+1);
    j++;
    }
return result;
}



