#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int s = a+b+c;

    cout << ((s % 9 == 0 && min({a, b, c}) >= s/9) ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}