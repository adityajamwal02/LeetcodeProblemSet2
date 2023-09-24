/*
You are given a binary string s that contains at least one '1'.
You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
Return a string representing the maximum odd binary number that can be created from the given combination.
Note that the resulting string can have leading zeros.

Example 1:
Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".

Example 2:
Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
*/

/// Sol 1

class Solution {
public:
    string maximumOddBinaryNumber(string s){
        int countOnes=0, countZeros=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                countOnes++;
            }else{
                countZeros++;
            }
        }
        string result="1";
        countOnes--;
        if(countOnes==0){
            string temp="";
            for(int i=0;i<countZeros;i++){
                temp+='0';
            }
            string ans=temp+result;
        return ans;
        }else{
            string temp;
            for(int i=0;i<countZeros;i++){
                temp+='0';
            }
            for(int i=0;i<countOnes;i++){
                temp+='1';
            }
        reverse(temp.begin(),temp.end());
        result=temp+result;
        }
    return result;
    }
};

/// Sol 2

class Solution {
public:
    string maximumOddBinaryNumber(string s){
        int countOnes=0, countZeros=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                countOnes++;
            }else{
                countZeros++;
            }
        }
        string result="1";
        countOnes--;
        string temp="";
        for(int i=0;i<countZeros;i++){
            temp+='0';
        }
        for(int i=0;i<countOnes;i++){
            temp+='1';
        }
        reverse(temp.begin(),temp.end());
        result=temp+result;
    return result;
    }
};
