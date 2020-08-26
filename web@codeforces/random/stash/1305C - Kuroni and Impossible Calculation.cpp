#include <bits/stdc++.h>
using namespace std;

const int SIZE = int(2e5) * 10;

int n, m;
int a[SIZE];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n <= m) {
        int ans = 1;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans = (ans * (abs(a[i] - a[j]) % m) % m);
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
//    int t; cin >> t;
//    while(t--)
        solve();
}
