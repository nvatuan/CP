#include <bits/stdc++.h>
using namespace std;

long long n, q, k;

void solve() {
    cin >> n >> q >> k;
    vector<long long> a (n+2);
    a[0] = 0; a[n+1] = k+1;
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<long long> c (n+2);
    for (int i=1; i<=n; i++) {
        c[i] = (a[i+1] - a[i-1] - 2);
        c[i] = c[i-1] + c[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << c[r] - c[l-1] + (a[l-1]) + (k - a[r+1] + 1)<< '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}