/// One Solution

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define vi vector<int>
#define F0(n, i) for(int i = 0; i < n; i++)
#define F1(n, i) for(int i = 1; i <= n; i++)
#define each(a) for(auto& e: a)

void solve() {
	int n, A = 1e5;
	cin >> n;
	vi a(n), cnt(A + 1), mul(A + 1), div(A + 1);
	F0(n, i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	F1(A, i) {
		for(int j = i; j <= A; j += i) {
			mul[i] += cnt[j];
			div[j] += cnt[i];
		}
	}
	each(a) cout << div[e] + mul[e] - cnt[e] - 1 << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
		cout << endl;
	}
}

/// Another Solution

vector solve(vector &nums) {
    vector ans;
    unordered_map<int, int> mp;
    for (int num: nums) {
        mp[num] += 1;
    }
    vector<int> dp(100001, 0);
    for (int i=1; i<=100000; i++) {
        if (mp.find(i) != mp.end()) {
            for (int j=i*2; j<=100000; j+=i) {
                if (mp.find(j) != mp.end()) {
                    dp[i] += mp[i] * mp[j];
                    dp[j] = dp[i];
                }
            }
        }
    }
    for (int num: nums) {
        ans.push_back(dp[num]);
    }
    return ans;
}
