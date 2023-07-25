/// Maximize The Average Working Ratio : Coding ninjas


#include <bits/stdc++.h>
using namespace std;

double getProfit(double a, double b) {
    return (a+1)/(b+1) - a/b;
}

double maxAverageWorkingRatio(vector<vector<int>>& bulbs, int n, int extra) {
    vector<double> profit(n);
    for (int i=0;i<n;i++) {
        profit[i]=getProfit(bulbs[i][0],bulbs[i][1]);
    }
    for (int i=0;i<extra;i++) {
        int pos=max_element(profit.begin(), profit.end())-profit.begin();
        bulbs[pos][0]++;
        bulbs[pos][1]++;
    profit[pos]=getProfit(bulbs[pos][0],bulbs[pos][1]);
    }
    double result = 0;
    for (auto it : bulbs) {
        result+=(double)it[0] / it[1];
    }
    result/=n;
return result;
}
