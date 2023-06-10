/*
A self-dividing number is a number that is divisible by every digit it contains.
For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.
Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].

Example 1:
Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]

Example 2:
Input: left = 47, right = 85
Output: [48,55,66,77]
*/


class Solution {
public:
    vector<int> helper(int n){
        vector<int> dig;
        while(n>0){
            dig.push_back(n%10);
            n/=10;
        }
    return dig;
    }

    bool isCheck(int n){
        vector<int> digits=helper(n);
        for(auto it : digits){
            if(it==0 or n%it!=0) return false;
        }
    return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left;i<=right;i++){
            if(isCheck(i)){
                result.push_back(i);
            }
        }
    return result;
    }
};
