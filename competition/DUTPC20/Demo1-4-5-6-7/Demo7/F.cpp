#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

llong MOD = (llong) 1e9 + 7;

llong phi(llong n) {
    llong result = n;
    for (llong i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            result = result / i * (i-1);
            while(n % i == 0) n /= i;
        }
    }
    if (n > 1) result = result / n * (n-1);
    return result;
}

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

    // number of x that gcd(x, n) = 1, times m
    //ans = phi(n) * m % MOD;
    // rotation = n
    //ans = ans + binExp(m, n) % MOD;

    for (llong d = 1; d*d <= n; d++) {
        if (n % d == 0) { // find number of x so gcd(x, n) = d
            llong seq = phi(n/d);
            ans = (ans + (binExp(m, d) * seq % MOD)) % MOD;

            if (d*d != n) {
                // find number of x so gcd(x, n) = n/d
                //                 <=> gcd(x, d) = 1
                seq = phi(d);
                ans = (ans + (binExp(m, n/d) * seq % MOD)) % MOD;
            }
        }
    }
    cout << ans * binExp(n, MOD-2) % MOD << '\n';
}