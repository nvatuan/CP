#include <bits/stdc++.h>
using namespace std;

long long a[4];

void solve() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    int op = (a[0] > 0 and a[1] > 0 and a[2] > 0);
    int even = 0;
    for (int ball : a) even += (ball % 2 == 0);

    string ans = "Yes";
    if (even == 2) ans = "No";
    if (even == 1 and not op) ans = "No";
    if (even == 0 and not op) ans = "No";
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}