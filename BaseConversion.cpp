/*
Given four numbers convert:

a, a decimal number to the binary equivalent
b, a binary to decimal equivalent
c, decimal to hexadecimal equivalent
d, hexadecimal to decimal equivalent

Example 1:
Input :
a = 6
b = 110
c = 20
d = 2A
Output:
110, 6, 14, 42
Explanation:
(6)10 = (110)2
(110)2 = (6)10
(20)10 = (14)16
(2A)16 = (42)10

Example 2:
Input:
a = 10
b = 111
c = 25
d = FA
Output:
1010, 7, 19, 250
Explanation:
(10)10 = (1010)2
(111)2 = (7)10
(25)10 = (19)16
(FA)16 = (250)10

Your Task:
You don't need to read input or print anything. Your task is to complete the function convert() which takes three integers a, b, c, and string d as input parameters and returns the converted numbers as an array of four strings.

Expected Time Complexity: O(log(max(a,b,c)) + |d|)
Expected Auxiliary Space: O(1)
*/

class Solution{
public:

    vector<string> convert(int a,int b,int c,string d)
    {
        vector<string> result;
        string res="";
        while(a!=0){
            int rem=a%2;
            res+=to_string(rem);
            a/=2;
        }
        reverse(res.begin(),res.end());
        result.push_back(res);

        int i=1, res2=0;
        while(b!=0){
            int rem=b%10;
            res2=res2+rem*i;
            i*=2;
            b/=10;
        }
        result.push_back(to_string(res2));

        string res3="";
        while(c!=0){
            int rem=c%16;
            if(rem<10){
                res3+=to_string(rem);
            }else{
                res3+=(char)('A'+(c%16)-10);
            }
            c/=16;
        }
        reverse(res3.begin(),res3.end());
        result.push_back(res3);

        int res4=0, base=1;
         for(int i=d.size()-1;i>=0;i--){
            if(d[i]>=0 and d[i]<='9'){
                res4+=(d[i]-48)*base;
                base=base*16;
            }
            else if(d[i]>='A' and d[i]<='F'){
                res4+=(d[i]-55)*base;
                base*=16;
            }

        }
        result.push_back(to_string(res4));
        return result;
    }
};
