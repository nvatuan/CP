#include <bits/stdc++.h>
using namespace std;

int n;
int a[(int)(2e5)];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    int c[3] = {};
    for (int i=0; i<n; i++) {
        c[a[i]%3]++;
    }

    int bl = n/3;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (c[a[i] % 3] > bl) {
            if (c[(a[i] + 1) % 3] < bl) {
                ans++;
                c[(a[i]+1)%3]++;
            } else {
                ans += 2;
                c[(a[i] + 2) % 3]++;
            }
            c[(a[i]) % 3]--;
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}