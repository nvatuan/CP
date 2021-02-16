#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int d = abs(a - b);
    cout << d / 10 + (d % 10 == 0 ? 0 : 1) << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}