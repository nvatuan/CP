#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int c[13];
int a[13][13];

void solve() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    // --
    long long ans = LLONG_MAX;
    for (int subset = 1; subset < (1 << n); subset++) {
        //
        vector<int> understanding (m, 0);
        int troubled = m;
        long long subans = 0;
        //
        for (int b = 0; b < n; b++) {
            if (subset & (1 << b)) {
                for (int j = 0; j < m; j++) {
                    if (understanding[j] < x) {
                        understanding[j] += a[b][j];
                        troubled -= (understanding[j] >= x);
                    }
                }
                subans += c[b];
            }
        }
        //
        if (troubled == 0) {
            ans = min(ans, subans);
        }
    }
    //
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}

int main() {
    solve();
}