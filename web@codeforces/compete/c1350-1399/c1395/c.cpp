#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[201], b[201];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    unordered_set<int> cand[2];
    int turn = 0;
    cand[0].insert(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int subC : cand[turn]) {
                cand[turn^1].insert(subC | (a[i]&b[j]));
            }
        }
        cand[turn].clear();
        turn ^= 1;
    }

    int ans = INT_MAX;
    for (int c : cand[turn]) ans = min(ans, c);
    cout << ans << endl;
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}