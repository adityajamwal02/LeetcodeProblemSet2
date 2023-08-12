/// get string

#include<bits/stdc++.h>
using namespace std;

string getString(string input_str){
    vector<pair<int,pair<char,int>>> vec(26);
    int n=input_str.size();
    for(int i=n-1;i>=0;i--){
        char ch=input_str[i];
        int index=ch-'a';
        vec[index].second.first=ch;
        vec[index].second.second++;
        if(vec[index].second.second==1) {
            vec[index].first=i;
        }
    }
    string result="";
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        if(vec[i].second.second>0){
            result+=vec[i].second.first;
            vec[i].second.second=0;
        }
    }
    return result;
    /*
    set<char> st;
    for(int i=0;i<input_str.size();i++){
        st.insert(input_str[i]);
    }
    string result="";
    for(auto it : st){
        result+=(it);
    }
    reverse(result.begin(),result.end());
return result;
*/
}


int main(){
    string str;
    cin>>str;
    string result=getString(str);
    cout<<result<<endl;

    return 0;
}
