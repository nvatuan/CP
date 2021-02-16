#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == y) cout << x*2 << '\n';
    else cout << max(x, y)*2 - 1 << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}