#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 200005;
const ll MOD = ll(1e9) + 7;
ll f[N], fr[N];

ll binExp(ll b, ll e) {
    if (e == 0) return 1LL;
    ll res = 1;
    while (e) {
        if (e & 1) res = b*res % MOD;
        b = b*b % MOD;
        e >>= 1;
    }
    return res;
}

void prep() {
    f[0] = 1;
    for (int i=1; i<N; i++) {
        f[i] = f[i-1] * i % MOD;
    }
    for (int i=0; i<N; i++) {
        fr[i] = binExp(f[i], MOD-2);
    }
}

ll C(ll k, ll n) {
    if (n < k) return 0;
    return f[n] * fr[k] % MOD * fr[n-k] % MOD;
}

int n, m, k;
vector<int> a;

void solve() {
    cin >> n >> m >> k;
    a.resize(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i=0; i<n; i++) {
        int up = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin() - 1;
        int num = up - i;
        ans += C(m-1, num);
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    prep();

    int t; cin >> t;
    while(t--)
        solve();
}