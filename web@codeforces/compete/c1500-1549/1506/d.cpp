#include <bits/stdc++.h>
using namespace std;

int n;
int a[(int)(2e5)+10];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    map<int, int> cnt;

    for (int i=0; i<n; i++) cnt[a[i]]++;

    int dominant=-1;
    for (auto p : cnt) {
        dominant = max(dominant, p.second);
    }

    if (dominant <= n/2) {
        if (n & 1) cout << 1;
        else cout << 0;
        cout << '\n';
        return;
    } else {
        cout << (n - 2*(n - dominant)) << '\n';
    }
    /*
    1 1 1 1 1 2 2
    */
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}