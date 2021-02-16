#include <bits/stdc++.h>
using namespace std;

const int N = int(2e5) + 10;
int n;
pair<int, int> seg[N];
int Left[N], Right[N];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> seg[i].first >> seg[i].second;
        Left[i] = seg[i].first;
        Right[i] = seg[i].second;
    }
    sort(Left, Left + n);
    sort(Right, Right + n);

    int ans = INT_MAX;
    for (int i=0; i<n; i++) {
        int lf = seg[i].first;
        int rg = seg[i].second;

        int on_left = upper_bound(Right, Right + n, lf-1) - Right - 1;
        int on_right = n - (lower_bound(Left, Left + n, rg+1) - Left) + 1;
        ans = min(ans, on_left + on_right);
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}