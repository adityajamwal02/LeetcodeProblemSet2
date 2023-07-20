/// Life And Death : Coding ninjas

#include<bits/stdc++.h>
using namespace std;

long long maximize(int p, int x){
    long long counter=0;
    while(p){
        p/=2;
        counter++;
    }
    return counter*x;
}

long long minimize(int p, int x){
    long long counter=0;
    while(p%2){
        p/=2;
        counter++;
    }
    return counter*x;
}


vector<long long> lifeAndDeath(int n, vector<int> v, int a, int x, int y) {
    vector<long long> result(2);
    for(int i=0;i<n;i++){
        result[0]=result[0]+(maximize(v[i], x));
        result[1]=result[1]+min(minimize(v[i],x),y+minimize(v[i]^a,x));
    }
    result[0]=result[0]+(y+maximize(a,x))*n;
    return result;
}
