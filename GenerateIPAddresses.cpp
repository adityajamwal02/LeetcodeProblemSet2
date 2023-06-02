/*
Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

For string 11211 the IP address possible are
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Example 1:
Input:
S = 1111
Output: 1.1.1.1

Example 2:
Input:
S = 55
Output: -1

Your Task:
Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses or -1 if no such IP address could be generated through the input string S, the only argument to the function.
Expected Time Complexity: O(N * N * N)
Expected Auxiliary Space: O(N * N * N * N)

Constraints:
1<=N<=16
here, N = length of S.
S only contains digits(i.e. 0-9)
*/


/*You are required to complete this method*/

class Solution{
  public:

    bool check(string s){
        if(s.size()<=0 or s.size()>3) return false;
        if(stoi(s)<0 or stoi(s)>255) return false;
        if(s[0]=='0' and s.size()>1) return false;
    return true;
    }

    string generate(string &s, int i, int j, int k, int n){
        string s1,s2,s3,s4;
        s1=s.substr(0,i+1);
        s2=s.substr(i+1,j-i);
        s3=s.substr(j+1,k-j);
        s4=s.substr(k+1,n-k-1);
        if(check(s1) and check(s2) and check(s3) and check(s4)){
            return s1+"."+s2+"."+s3+"."+s4;
        }else{
            return "";
        }
    }
    vector<string> genIp(string &s) {
        int n=s.size();
        vector<string> result;
        string temp="";
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    temp=generate(s,i,j,k,n);
                    if(temp.size()>0){
                        result.push_back(temp);
                    }
                }
            }
        }
    return result;
    }
};
