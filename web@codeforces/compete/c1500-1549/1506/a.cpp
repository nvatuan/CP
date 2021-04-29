#include <bits/stdc++.h>
using namespace std;

long long n, m, x;

void solve() {
    cin >> n >> m >> x;
    int r = (x-1) % n;
    int c = (x-1) / n;
    cout << r * m + c + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}