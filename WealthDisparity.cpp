/// Wealth Disparity : Problem Code: INOI1601

#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &vec, int s, long long &result, vector<long long> &employee, long long emp){
    for(int it : vec[s]){
        result=max(result,employee[s-1]-employee[it-1]);
        result=max(result,emp-employee[it-1]);
        long long ans=max(emp,employee[it-1]);
        dfs(vec,it,result,employee,ans);
    }
}

int main() {
    int n;
    cin>>n;
    vector<long long> employee(n);
    for(int i=0;i<n;i++){
        cin>>employee[i];
    }
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        cin>>parent[i];
    }
    vector<vector<int>> vec(n+1,vector<int>());
    int s;
    for(int i=0;i<n;i++){
        if(parent[i]!=-1){
            vec[parent[i]].push_back(i+1);
        }else{
            s=i+1;
        }
    }
    long long result=LLONG_MIN;
    long long emp=employee[s-1];
    dfs(vec,s,result,employee,emp);
    cout<<result;

	return 0;
}
