/// Bucket Sort


#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<double> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        double key=arr[i];
        int j=i-1;
        while(j>=0 and arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

vector<double> sortArray(int n, vector<double>& arr) {
    int count=10;
    vector<vector<double>> result(count);
    for (int i = 0; i < count; ++i) {
        result[i] = vector<double>();
    }

    for (double j : arr) {
        int index_b = int(j*count);
        result[index_b].push_back(j);
    }
    for (int i = 0; i < count; ++i) {
        insertionSort(result[i]);
    }

    int k = 0;
    for (int i = 0; i < count; ++i) {
        for (double j : result[i]) {
            arr[k] = j;
            ++k;
        }
    }
    return arr;
}

