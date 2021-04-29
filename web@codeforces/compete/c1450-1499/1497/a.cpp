#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;
    map<int, int> m;
    for (int i : a) m[i]++;

    for (int i=0; i<n; i++) {
        if (m[i]) {
            m[i]--;
            cout << i << ' ';
        } else {
            break;
        }
    }

    for (auto p : m) {
        if (p.second > 0) {
            for (int j=0; j<p.second; j++) cout << p.first << ' ';
        }
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}