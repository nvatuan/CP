#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve() {
    cin >> n >> k;
    // |n| -> |n-2|
    if (k <= n) {
        if (k % 2 == n % 2) cout << "0\n";
        else cout << "1\n";
    } else {
        cout << k - n << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}