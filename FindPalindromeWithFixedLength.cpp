/*
Given an integer array queries and a positive integer intLength, return an array answer where answer[i] is either the queries[i]th smallest positive palindrome of length intLength or -1 if no such palindrome exists.
A palindrome is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.

Example 1:
Input: queries = [1,2,3,4,5,90], intLength = 3
Output: [101,111,121,131,141,999]
Explanation:
The first few palindromes of length 3 are:
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
The 90th palindrome of length 3 is 999.

Example 2:
Input: queries = [2,4,6], intLength = 4
Output: [1111,1331,1551]
Explanation:
The first six palindromes of length 4 are:
1001, 1111, 1221, 1331, 1441, and 1551.
*/

class Solution {
public:
    long long findMinimumNDigitNumber(int num){
        if(num==0){
            return 0;
        }
        if(num==1){
            return 9;
        }
    return 10*findMaximumNDigitNumber(num-1)+9;
    }
    long long findMaximumNDigitNumber(int num){
        if(num==1){
            return 9;
        }
    return 10*findMaximumNDigitNumber(num-1)+9;
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength){
        int n=queries.size(), lengthReq=(intLength+1)/2;
        vector<long long> result(n);
        long long minVal=findMinimumNDigitNumber(lengthReq-1)+1;
        long long maxVal=findMaximumNDigitNumber(lengthReq);
        long long totalCount=maxVal-minVal+1;
        for(int i=0;i<n;i++){
            if(queries[i]>totalCount){
                result[i]=-1;
            }else{
                long long num=minVal+(queries[i]-1);
                string str1=to_string(num);
                string str2=str1;
                reverse(str2.begin(),str2.end());
                if(intLength%2==0){
                    str1=str1+str2;
                    long long currResult=stoll(str1);
                    result[i]=currResult;
                }else{
                    string temp=str1;
                    for(int j=1;j<str2.size();j++){
                        temp+=str2[j];
                    }
                    long long currResult=stoll(temp);
                    result[i]=currResult;
                }
            }
        }
    return result;
    }
};
