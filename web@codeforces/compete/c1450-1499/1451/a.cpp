#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 1) cout << 0 << '\n';
    else
    if (n == 2) printf("1\n");
    else
    if (n == 3) printf("2\n");
    else
    if (n & 1) {
        cout << 3 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}