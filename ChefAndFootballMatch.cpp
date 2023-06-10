/// Chef and Football Match : Codechef question : Rating 1700

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    bool know=false;
	    int prev_a=-1, prev_b=-1;
	    for(int i=0;i<n;i++){
	        int type, a, b;
	        cin>>type>>a>>b;
	        if(type==1){
	            cout<<"YES"<<endl;
	            know=1;
	        }else{
	            if(min(a,b)>=max(prev_a,prev_b)){
	                cout<<(a==b ? "YES" : "NO")<<endl;
	                know=0;
	            }else{
	                cout<<((know or (a==b)) ? "YES" : "NO")<<endl;
	            }
	        }
	        prev_a=a;
	        prev_b=b;
	    }
	}
	return 0;
}
