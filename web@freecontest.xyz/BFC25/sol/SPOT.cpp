#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int xs[N], ys[N];

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        xs[i] = a; ys[i] = b;
    }
    sort(xs, xs+n); sort(ys, ys+n);

    long long ans = 0;
    int midx = xs[n/2], midy = ys[n/2];
    for (int i=0; i<n; i++) {
        ans += abs(xs[i] - midx);
        ans += abs(ys[i] - midy);
    }
    cout << ans << '\n';
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
}