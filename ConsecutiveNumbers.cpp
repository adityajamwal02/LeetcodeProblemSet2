/*
You are given a positive integer ‘N’. Find the smallest positive integer ‘K’ such that (‘K’ XOR ‘K-1’) equals ‘N’.
Here ‘XOR’ denotes the bitwise XOR operator denoted by ^.
If no such ‘K’ exists, return -1.

Input Format :
The first line contains a single integer ‘T’ representing the number of test cases.Then test cases follows :
The first line of each test case contains an integer ‘N’.

Output Format :
For each test case, print the value of ‘K’ or -1 if no such ‘K’ exists.
Print the output of each test case in a new line.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 100
1 <= N <= 10^9

Time Limit : 1 sec
*/

#include <bits/stdc++.h>
int findSmallestN(int n) {
    for(int i=1;i<=n;i++){
        if((i^(i-1))==n) return i;
    }
return -1;
}


/// Optimal solution

#include <bits/stdc++.h>
int findSmallestN(int n) {
    if((n&(n+1))==0) return n/2+1;
return -1;
}
