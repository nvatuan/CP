#include <bits/stdc++.h>
using namespace std;

int n;
int b[(int)(3e5)];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> b[i];
    sort(b, b+n);

    int l = 0, r = n-1;
    while (l < n and b[l] == l+1) l++;
    while (r >= 0 and b[r] == r+1) r--;

    int ans = n - l - (n-1-r);
    if (l >= r) cout << ans << '\n';
    else {
        ans -= (b[l] - l - 1);
        ans -= (b[r])
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}