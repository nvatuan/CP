#include <bits/stdc++.h>
using namespace std;

long long cal(int f, int s, int fx, int sx, int n) {
    int tmp = min(f - fx, n);
    f -= tmp;
    n -= tmp;
    
    tmp = min(s - sx, n);
    s -= tmp;
    return 1LL * f * s;
}

void solve() {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << min(
        cal(a, b, x, y, n),
        cal(b, a, y, x, n)
    ) << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}