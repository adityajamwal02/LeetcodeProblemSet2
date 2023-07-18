/// Dense Bracket Sequence : Codechef : Problem Code: DENSE

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string str;
	    cin>>str;
	    int counter=0, i=0, j=n-1;
	    while(i<=j){
	        if(str[i]=='(' and str[j]==')'){
	            counter+=2;
	            i++;
	            j--;
	        }else if(str[i]==')'){
	            i++;
	        }else if(str[j]=='('){
	            j--;
	        }
	    }
	    cout<<n-counter<<endl;
	}
	return 0;
}
