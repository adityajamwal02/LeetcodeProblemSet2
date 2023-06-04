/*
Given a string str consisting of multiple words, reverse alternate words in str.

Example 1:

Input:
str = geeks for geeks
Output: geeks rof geeks
Explanation: First and thrid word are as it is.
Second word is reversed.

Example 2:

Input:
str = hello there peter pan
Output: hello ereht peter nap
Explanation: second and fourth words are reversed.

Your Task:
You dont need to read input or print anything. Complete the function reverseAlternate() which takes string str as input parameter and returns the resultant string.


Expected Time Complexity: O(N) where N is the length of str.
Expected Auxiliary Space: O(N)


Constraints:
1<= str.length() <= 104
*/



class Solution{
    public:
    string reverseAlternate(string str)
{
    string result="", temp="";
    int flag=0, n=str.size();
    for(int i=0;i<n;i++){
        if(str[i]!=' '){
            temp+=str[i];
        }else{
            flag++;
            if(flag==1){
            result+=temp;
            result+=" ";
            temp="";
           }else if(flag==2){
               reverse(temp.begin(),temp.end());
               result+=temp;
               temp="";
               result+=" ";
               flag=0;
            }
        }
    }
        if(flag==1){
            reverse(temp.begin(),temp.end());
            result+=temp;
        }
        if(flag==0){
            result+=temp;
        }
    return result;
    }
};

