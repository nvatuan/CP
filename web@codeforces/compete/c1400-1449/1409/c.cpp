#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, n;
    cin >> n >> x >> y;

    long long ans = LLONG_MAX;
    int dans = 0;
    for (int ix = 1; ix <= n; ix++) {
        for (int iy = ix+1; iy <= n; iy++) {
            if ( (y - x) % (iy - ix) == 0 ) {
                int d = (y-x)/(iy-ix);
                long long mx = 1LL * (n - iy) * d + y;
                long long mn = mx - (n - 1)*d;
                if (mn > 0) {
                    if (ans > mx) {
                        ans = min(ans, mx); dans = d;
                    }
                }
            }
        }
    }
    
    while(n--) {
        cout << ans << ' ';
        ans -= dans;
    }
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}