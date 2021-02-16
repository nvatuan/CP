#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int SIZE = 1500005; 
long long f[SIZE], fr[SIZE];

long long binExp(long long b, long long e) {
    long long result = 1;
    while (e > 0) {
        if (e & 1) result = result * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return result;
}

long long C(int k, int n) {
    assert(n >= k);
    return f[n] * fr[k] % MOD * fr[n-k] % MOD;
}

void solve() {
    int n; cin >> n; n *= 2;
    vector<long long> a (n);
    for (long long &i : a) cin >> i;
    
    sort(a.begin(), a.end());

    long long del = 0;
    for (int i=0, j=n-1; i<j; i++,j--) del += (a[j] - a[i]);
    // cout << del << endl;

    cout << 1LL * C(n/2, n) * (del % MOD) % MOD << '\n';
}

int main() {
    f[0] = f[1] = 1;
    for (int i=2; i<SIZE; i++) f[i] = f[i-1] * i % MOD;
    for (int i=0; i<SIZE; i++) fr[i] = binExp(f[i], MOD-2);

    // int t; cin >> t;
    // while (t--)
        solve();
}