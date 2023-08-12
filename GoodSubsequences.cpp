#include <iostream>
#include <vector>

using namespace std;

const int N = 10001;
const int MOD = 1000000007;
vector<long long> F(N);
vector<long long> G(N);

long long qmi(long long a, long long k, long long p) {
    long long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % p;
        }
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

void preprocess() {
    F[0] = 1;
    G[0] = 1;
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i % MOD;
        G[i] = qmi(F[i], MOD - 2, MOD);
    }
}

long long comb(int n, int k) {
    return (F[n] * G[k] % MOD) * G[n - k] % MOD;
}

int countGoodSubsequences(string word) {
    vector<int> cnt(26);
    int mx = 1;
    for (char c : word) {
        mx = max(mx, ++cnt[c - 'a']);
    }
    long long ans = 0;
    for (int i = 1; i <= mx; ++i) {
        long long x = 1;
        for (int j = 0; j < 26; ++j) {
            if (cnt[j] >= i) {
                x = x * (comb(cnt[j], i) + 1) % MOD;
            }
        }
        ans = (ans + x - 1 + MOD) % MOD;
    }
    return static_cast<int>(ans);
}

int main() {
    preprocess();
    string word = "Baab";  // Replace with your input string
    int result = countGoodSubsequences(word);
    cout << "Result: " << result << endl;
    return 0;
}
