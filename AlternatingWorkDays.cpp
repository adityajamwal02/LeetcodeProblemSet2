/// Alternating Work Days : Codechef : Problem Code: ALTER

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,p,q;
	    cin>>a>>b>>p>>q;
	    if(a==p and b==q) cout<<"YES"<<endl;
	    else{
	        int num1=p/a;
	        int num2=q/b;
	        if(abs(num2-num1)<=1 and p%a==0 and q%b==0){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }
	    }
	}
	return 0;
}
