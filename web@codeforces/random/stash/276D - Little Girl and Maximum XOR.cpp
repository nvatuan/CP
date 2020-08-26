#include <bits/stdc++.h>
using namespace std;

const int SIZE = int(2e5) * 10;

typedef long long llong;
int offsetRange(llong x, llong L, llong R) { // [L, R]
    if (x > R) return 1;
    if (x < L) return -1;
    return 0;
}

llong l, r;

void solve() {
    cin >> l >> r;
    llong mid = 0;
    int bit = 0;

    for (bit = 62; bit >= 0; bit--) {
        int rval = offsetRange(mid + (1LL << bit), l, r);
        if (rval <= 0) {
            mid += (1LL << bit);
        }
        if (offsetRange(mid - 1, l, r) == 0) {
            break;
        }
    }

    llong ans = 0;
    for (; bit >= 0; bit--) ans |= (1LL << bit);
    cout << ans << '\n';
}

int main() {
//    int t; cin >> t;
//    while(t--)
        solve();
}
