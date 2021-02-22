#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
const long long MOD = (long long) (1e9) + 7;

void solve() {
    long long subsum = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        subsum = (subsum + a[i]) % MOD;
    }

    long long ans = 0;
    for (int i=0; i<n; i++) {
        subsum = (subsum - a[i] + MOD) % MOD;
        ans = (ans + (a[i]) * subsum % MOD) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}