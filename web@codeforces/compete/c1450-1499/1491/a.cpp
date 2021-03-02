#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[(int)(2e5)];

void solve() {
    cin >> n >> q;
    int ones=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ones += a[i];
    }

    while (q--) {
        int op; cin >> op;
        op--;
        if (op) {
            int k; cin >> k;
            if (k <= ones) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            int i; cin >> i;
            i--;
            ones -= a[i];
            a[i] ^= 1;
            ones += a[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}