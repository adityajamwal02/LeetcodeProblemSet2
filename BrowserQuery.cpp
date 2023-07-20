/// Browser Query : Coding Ninjas

// Brute Force:

#include <bits/stdc++.h>
using namespace std;

vector<int> browserQuery(int n, int m, int q, vector<string> websites, vector<string> queries)
{
	vector<int> result(q);
	for(int i=0;i<q;i++){
		string curr=queries[i];
		int counter=0;
		for(int j=0;j<n;j++){
			string temp=websites[j];
			bool flag=true;
			for(int k=0;k<m;k++){
				if(curr[k]=='?' or curr[k]==temp[k]){
					flag&=true;
				}else{
					flag&=false;
					break;
				}
			}
			if(flag==true) counter++;
		}
	result[i]=counter;
	}
	return result;
}

// Accepted Solution (Bitmasking on strings)

#include <bits/stdc++.h>
using namespace std;

vector<int> browserQuery(int n, int m, int q, vector<string> websites, vector<string> queries)
{
	vector<int> result;
	unordered_map<string,int> mp;
	for(int i=0;i<n;i++){
		string curr=websites[i];
		for(int j=0;j<(1<<m);j++){
			string modified=curr;
			for(int k=0;k<m;k++){
				if ((j & (1 << k)) > 0) {
				modified[k] = '?';
				}
			}
		mp[modified]++;
		}
	}
	for(int i=0;i<q;i++){
		result.push_back(mp[queries[i]]);
	}
    return result;
}
