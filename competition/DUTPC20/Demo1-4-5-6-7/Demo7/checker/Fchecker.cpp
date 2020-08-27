#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

llong MOD = (llong) 1e9 + 7;
llong n, m;
llong ans;

llong binExp(llong b, llong e) {
    if (e == 0) return 1LL;
    if (e == 1) return b % MOD;
    if (e & 1) return binExp(b*b % MOD, e/2) % MOD * b % MOD;
    else return binExp(b*b % MOD, e/2) % MOD;
}


int main() {
    cin >> n >> m;

    llong ans = 0;
    for (llong d = 1; d <= n; d++) {
        llong g = __gcd(d, n);
        ans = (ans + binExp(m, g)) % MOD;
    }
    cout << ans * binExp(n, MOD-2) % MOD << '\n';
}