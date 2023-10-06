/// Minimum Cost To Make String Valid

#include <bits/stdc++.h>
int findMinimumCost(string str){
  int n=str.size(), open=0, close=0;
  if(n&1) return -1;
  for (int i = 0; i < n; i++) {
    if (str[i] == '}') {
      if(open!=0) open--;
      else close++;
    } else {
        open++;
    }
  }
  return (open+1)/2+(close+1)/2;;
}
