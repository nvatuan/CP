#include <bits/stdc++.h>
using namespace std;

int n, k;
int x[1000], y[1000];

void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    int mxCnt = 0;
    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=0; j < n; j++) 
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k) cnt++;
        mxCnt = max(mxCnt, cnt);
    }

    cout << (mxCnt == n ? 1 : -1) << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}