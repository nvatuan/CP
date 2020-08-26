#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

llong f[int(1e6) + 5], dp[int(1e6) + 5];
int n;

llong MOD = int(1e9) + 7;

void solve() {
    f[0] = 1; for (int i = 1; i <= int(1e6); i++) f[i] = f[i-1] * i % MOD;
    //
    dp[3] = 2;
    cin >> n;
    for (int i = 4; i <= n; i++) {
        dp[i] = (
            (f[i-1] - dp[i-1] + MOD) % MOD * (i - 2)
            + (dp[i-1] * (i) % MOD) % MOD
        ) % MOD;
    }
    cout << dp[n] << endl;
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}