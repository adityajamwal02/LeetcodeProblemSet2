/*
Given an integer N. Your task is to find the number of binary strings of length N having no consecutive 1s.
As the number can be large, return the answer modulo 10^9+7.

Example 1:
Input:
N = 3
Output:
5
Explanation:
All the binary strings of length 3 having
no consecutive 1s are "000", "001", "101",
"100" and "010".

Example 2:
Input:
N = 2
Output:
3
Explanation:
All the binary strings of length 2 having no
consecutive 1s are "10", "00" and "01".
Your Task:
You dont need to read input or print anything. Complete the function countStrings() which takes the integer N as the input parameter, and returns the number of binary strings of length N with no consecutive 1s.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(Height of the recursive call stack)

Constraints:
1 ≤ N ≤ 1018
*/

// User function Template for C++

class Solution {
  public:
    void matpow(long long n, long long a[2][2], long long res[2][2]){
        if(n==0){
            res[0][0]=res[1][1]=1;
            res[1][0]=res[0][1]=0;
            return;
        }
        long long temp[2][2];
        matpow(n/2,a,temp);
        mul(temp,temp,res);
        if(n&1){
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    temp[i][j]=res[i][j];
                }
            }
            mul(a,temp,res);
        }
    }

    void mul(long long a[2][2],long long b[2][2],long long c[2][2]){
        int mod=1e9+7;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                c[i][j]=0;
                for(int k=0;k<2;k++){
                    c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%mod)%mod;
                }
            }
        }
    }

    int countStrings(long long int N) {
        long long mat[2][2]={{1,1},{1,0}};
        long long res[2][2];
        matpow(N+1,mat,res);
    return res[0][0];
    }
};
