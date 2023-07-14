/// Best Line


#include <bits/stdc++.h>
using namespace std;

int pointsOnLine(int n, vector < vector < int >> & arr) {
      sort(arr.begin(),arr.end());
      int counter=0;
      for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            int yAxis=0;
            for(int j=i+1;j<n;j++){
                  int dy=arr[j][1]-arr[i][1];
                  int dx=arr[j][0]-arr[i][0];
                  if(dx==0){
                        yAxis++;
                  }else{
                        double slope=(double)dy/dx;
                        mp[slope]++;
                  }
            }
            for(auto it : mp){
                  counter=max(counter,it.second);
            }
      counter=max(counter,yAxis);
      }
return counter+1;
}
