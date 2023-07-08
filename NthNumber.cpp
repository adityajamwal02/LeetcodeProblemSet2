/// Coding Ninjas (Hard) Digit DP + Binary Search


#include <bits/stdc++.h>
using namespace std;

long long dp[100][12][2];

long long digitDP(string &str, long long n, long long sum, bool flag){
   if(sum<0) return 0;
   if(n==0){
      if(sum==0) return 1;
   return 0;
   }
   if(dp[n][sum][flag]!=-1) return dp[n][sum][flag];
   long long result=0;
   int ub=(flag ? (str[str.size()-n]-'0') : 9);
   for(int i=0;i<=ub;i++){
      result+=digitDP(str,n-1,sum-i,flag&(i==ub));
   }

return dp[n][sum][flag]=result;
}

long long nthNumberWithSum10(long long n)
{
   long long low=0, high=LLONG_MAX;
   long long result=high;
   while(low<=high){
      long long mid=low+(high-low)/2;
      string str=to_string(mid);
      memset(dp,-1,sizeof(dp));
      long long counter=digitDP(str,str.size(),10,1);
      if(counter>=n){
         result=mid;
         high=mid-1;
      }else{
         low=mid+1;
      }
   }
return result;
}
