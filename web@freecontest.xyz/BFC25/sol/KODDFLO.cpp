#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[123456];

long long ans = 0;

void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    
    map<int, long long> evensLeft, evensRight;
    int even = 0;
    for (int i=0; i<n; i++) {
        if (a[i] & 1) {
            evensLeft[i] = even;
            even = 0;
        } else even++;
    }
    even = 0;
    for (int i=n-1; i>=0; i--) {
        if (a[i] & 1) {
            evensRight[i] = even;
            even = 0;
        } else even++;
    }    
    // for (int i=0; i<n; i++) {
    //     cout << evensLeft[i] << ' ';
    // }
    // cout << endl;
    // for (int i=0; i<n; i++) {
    //     cout << evensRight[i] << ' ';
    // }
    // cout << endl;

    vector<int> oddsOnly;
    for (int i = 0; i<n; i++)
        if (a[i] & 1)
            oddsOnly.push_back(i);

    int l = 0, r = k-1;
    while (r < (int) oddsOnly.size()) {
        ans += 1LL * (evensLeft[oddsOnly[l]] + 1) * (evensRight[oddsOnly[r]] + 1);
        l++, r++;
    }
    cout << ans << '\n';
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
}