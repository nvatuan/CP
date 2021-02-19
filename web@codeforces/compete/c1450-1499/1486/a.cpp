#include <bits/stdc++.h>
using namespace std;

int n;
int a[10000];

void solve() {
    cin >> n;
    long long spare = 0;
    int poss = 1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        spare += (a[i] - i);
        if (spare < 0) {
            poss = 0;
        }
    }
    cout << (poss ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}