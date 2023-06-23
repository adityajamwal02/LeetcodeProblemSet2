/*
Given two positive integers L, R and a digit D, find out all the good numbers in the range [L, R], which do not contain the digit D.
A number is a good number if it's every digit is larger than the sum of digits which are on the right side of that digit.
9620  is good as (2 > 0, 6 > 2+0, 9 > 6+2+0)

Example 1:

Input:
L=200
R=700
D=4
Output:
{210, 310, 320, 510, 520, 521, 530, 531,
610, 620, 621, 630, 631, 632, 650}
Explanation:
These are the only good numbers in the range
[200,700]
Example 2:

Input:
L=100
R=500
D=5
Output:
{210, 310, 320, 410, 420, 421, 430}
Explanation:
These are the only good numbers in the range
[100,500]

Your Task:
You don't need to read input or print anything. Your task is to complete the function goodNumbers() which takes 3 integers L, R, and D as input parameters and returns all the good numbers in the range [L, R]. (Returns empty if there are no good numbers in that range)
*/


class Solution {
  public:

    bool isGood(int num, int d){
        int digit=num%10;
        int sum=digit;
        if(digit==d) return false;
        num/=10;
        while(num>0){
            digit=num%10;
            if(digit==d or digit<=sum) return false;
            else{
                sum+=digit;
                num/=10;
            }
        }
    return true;
    }
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> result;
        for(int i=L;i<=R;i++){
            if(isGood(i,D)){
                result.push_back(i);
            }
        }
    return result;
    }
};
