#include <bits/stdc++.h>
using namespace std;

string s, t;
int ans = INT_MAX;

void solve() {
    cin >> s >> t;
    int n = s.length();
    int k = t.length();
    for (int i=0; i+k<=n; i++) {
        int subans = 0;
        for (int j=0; j<k; j++) subans += (s[i+j] != t[j]);
        ans = min(ans, subans);
    }
    cout << ans << '\n';
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}