#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    int curr = a[0]-1;
    int cnt = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (curr != a[i]) {
            curr = a[i];
            cnt = 1;
        } else {
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}