/// Count Total Set bits from 1 - N

/// Most Efficient Solution (O(logn))

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int N)
{
    int counter=0;
    for(int i=1;i<=N;i<<=1){
        int div=i<<1;
        counter+=(N/div)*i + max(0,min(N%div-i+1,i));
    }
return counter;
}
