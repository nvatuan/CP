#include <bits/stdc++.h>
using namespace std;

int a, b, k;

void solve() {
    cin >> a >> b >> k;
    map<int, int> cntU, cntV;
    vector<pair<int, int>> vp (k);
    for (int i=0; i<k; i++) {
        int x; cin >> x; cntU[x]++;
        vp[i].first = x;
    }
    for (int i=0; i<k; i++) {
        int x; cin >> x; cntV[x]++;
        vp[i].second = x;
    }
    long long ans = 0;
    for (pair<int, int> p : vp) {
        ans += (k - cntU[p.first] - cntV[p.second] + 1);
    }
    cout << ans/2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}