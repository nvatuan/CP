#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a[100];
    for (int i=0; i<n; i++) cin >> a[i];

    int ans = 0;
    for (int i=0; i<n-1; i++) {
        int mn = min(a[i], a[i+1]);
        int mx = max(a[i], a[i+1]);
        while (mn * 2 < mx) {
            ans++;
            mn *= 2;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}