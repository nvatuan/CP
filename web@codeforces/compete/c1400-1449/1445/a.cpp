#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[10000], b[10000];

void solve() {
    cin >> n >> x;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n, greater<int>());

    bool possible = true;
    for (int i=0; i<n; i++) {
        if (a[i] + b[i] > x) possible = false;
    }
    cout << (possible ? "Yes\n" : "No\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}