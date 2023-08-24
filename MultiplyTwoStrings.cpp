/*
Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers.

Example 1:
Input:
s1 = "0033"
s2 = "2"
Output:
66

Example 2:
Input:
s1 = "11"
s2 = "23"
Output:
253
Your Task: You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.

Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        string temp1=s1, temp2=s2;
        if(s1[0]=='-' and s2[0]!='-'){
           s1=s1.substr(1);
        }else if(s1[0]!='-' and s2[0]=='-'){
           s2=s2.substr(1);
        }else if(s1[0]=='-' and s2[0]=='-'){
           s1=s1.substr(1);
           s2=s2.substr(1);
        }
        string num1=s1, num2=s2;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n=s1.size(), m=s2.size();
        vector<int> arr(n+m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i+j]=arr[i+j]+(num1[i]-'0')*(num2[j]-'0');
            }
        }
        string product="";
        for(int i=0;i<arr.size();i++){
            int dig=arr[i]%10;
            int carr=arr[i]/10;
            if(i+1<arr.size()){
                arr[i+1]=arr[i+1]+carr;
            }
            product=to_string(dig)+product;
        }
        while(product.size()>1 and product[0]=='0'){
            product=product.substr(1);
        }
        if(temp1[0]=='-' and temp2[0]!='-') {
            product="-"+product;
        }
        else if(temp1[0]!='-' and temp2[0]=='-') {
            product="-"+product;
        }
    return product;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }

}
// } Driver Code Ends
