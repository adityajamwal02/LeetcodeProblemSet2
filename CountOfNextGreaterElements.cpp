/// Coding Ninjas

vector<int> countGreater(vector<int> &arr, vector<int> &query) {
    int n = arr.size(), q = query.size();
    vector<int> result(q, 0);
    for(int i = 0; i < q; i++) {
        int index = query[i];
        for(int j = index+1; j < n; j++) {
            if(arr[j]>arr[index])
                result[i]++;
            }
        }
    return result;
}
