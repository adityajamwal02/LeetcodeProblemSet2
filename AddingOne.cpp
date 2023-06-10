/*
Given a non-negative integer(without leading zeroes) represented as an array A of N digits. Your task is to add 1 to the number (increment the number by 1). The digits are stored such that the most significant digit is at the starting index of the array.

Example 1:
Input:
N = 4
A[] = {5, 6, 7, 8}
Output: 5 6 7 9
Explanation: 5678 + 1 = 5679

Example 2:
Input:
N = 3
A[] = {9, 9, 9}
Output: 1 0 0 0
Explanation: 999 + 1 = 1000
Your Task:
You don't need to read input or print anything. Your task is to complete the function addOne() which takes the array of integers a and n as parameters and returns an list of integers denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) for the list of integers used to store the returning result.
*/

class Solution{
public:
    vector<int> addOne(int a[], int n) {
        vector<int> result;
        int carry=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]!=9 and carry==0){
                a[i]++;
                break;
            }
            else if(a[i]!=9 and carry==1){
                a[i]++;
                carry=0;
                break;
            }else if(a[i]==9 and i!=0 and carry==1){
                a[i]=0;
                carry=1;
            }else{
                a[i]=0;
                carry=1;
            }
        }
        if(carry==1){
            result.push_back(1);
        }
        for(int i=0;i<n;i++){
            result.push_back(a[i]);
        }
    return result;
    }
};
