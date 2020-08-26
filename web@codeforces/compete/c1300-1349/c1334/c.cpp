#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

// ----
int n;
vector<llong> a (300001), b (300001), aa (300001);

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        aa[i] = a[i];
    }
    // --
    for (int i = 0; i < n; i++) {
        aa[i] = max(0LL, a[i] - b[(i - 1 + n) % n]);
    }
    llong anss = LLONG_MAX;
    llong ans = 0;
    for (int i = 0; i < n; i++) ans += aa[i];
    for (int i = 0; i < n; i++) {
        anss = min(anss, ans - aa[i] + a[i]);
    }
    cout << anss << '\n';
}
// ----

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    for (cin >> t; t; t--) solve();
}