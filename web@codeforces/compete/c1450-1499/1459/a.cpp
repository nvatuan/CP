#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string r, b;
    cin >> n;
    cin >> r >> b;

    int rg = 0;
    int re = 0;
    for (int i=0; i<n; i++) {
        rg += (r[i] > b[i]);
        re += (r[i] == b[i]);
    }

    if (n - re - rg == rg) {
        cout << "EQUAL\n";
    } else {
        if (n - re - rg < rg) cout << "RED\n";
        else cout << "BLUE\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}