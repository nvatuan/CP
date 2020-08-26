#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int b[100005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int Min = b[0];

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            possible &= (__gcd(Min, a[i]) == Min);
        }
    }
    cout << (possible ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}