#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = (ll)(1e9)+7;
ll n, p;

ll pow_mod(ll b, ll e, const ll& m) {
    if (e < 0) return 0;
    ll res = 1;
    while (e) {
        if (e & 1) res = (res * b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> p;
    cout << (p-1) * pow_mod(p-2, n-1, MOD) % MOD << endl;
}

