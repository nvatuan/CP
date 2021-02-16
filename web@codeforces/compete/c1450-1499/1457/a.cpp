#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    cout << max({
        r-1 + c-1, r-1 + m-c,
        n-r + c-1, n-r + m-c
    }) << endl;
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}