/// Problem Code: FILL01 : Sleepy chef : Codechef

/// Solution 1 : Variation 1 of Sliding Window

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    int counter=0;
	    if(k==1){
	        for(int i=0;i<n;i++){
	            if(s[i]=='0') counter++;
	        }
	        cout<<counter<<endl;
        }else{
            int temp=0;
	        for(int i=0;i<n;i++){
	            if(s[i]=='0'){
	               temp++;
                    if(temp%k==0){
                        counter++;
                    }
	            }else{
	                temp=0;
	            }
	       }
	    cout<<counter<<endl;
	    }
	}
	return 0;
}

/// Solution 2 : Variation 2 of Sliding Window

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    int i=0,j=0,cnt=0,ans=0;
	    while(j<n&&i<n){
	        if(s[j]=='0'){cnt++;}
	        if(j-i+1==k){
	            if(cnt==k){
	                ans++;cnt=0;i=j+1;
	            }
	            else{
	                if(s[i]=='0'){cnt--;}
	                i++;
	            }
	        }
	        j++;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}


/// Solution 3 : Stack Based Solution

stack<char> st;
void solve()
{
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        st.push(a[i]);
    }
    int count =0;
    int num=0;
    while(!st.empty())
    {
        char s;
        s=st.top();
        st.pop();
        if(s=='0')
        {
            count++;
            if(count==k)
            {
                num++;
                count=0;
            }
        }
        else if(s=='1')
        {
            count=0;
        }
    }
    cout<<num<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
