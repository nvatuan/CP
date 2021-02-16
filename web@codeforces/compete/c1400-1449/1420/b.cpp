#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    map<int, int> msb;
    for (int i=0; i<n; i++) msb[31 - __builtin_clz(a[i])]++;

    long long ans = 0;
    for (int i=0; i<n; i++) {
        msb[31 - __builtin_clz(a[i])]--;
        ans += (msb[31 - __builtin_clz(a[i])]);
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}