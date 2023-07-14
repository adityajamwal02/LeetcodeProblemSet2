/// Polygon Relationship : Problem Code: POLYREL

#include <bits/stdc++.h>;
using namespace std;

int child(int n) {
    if (n < 6) {
        return n;
    } else {
        return n + child(n / 2);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        cout << child(n) << endl;
    }

    return 0;
}
