#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[(int)(2e5)+5];
int b[(int)(2e5)+5];

int check(int x) {
    for (int i=0; i<n; i++) {
        b[i] = (a[i] >= x ? 1 : -1);
        b[i] = (i > 0 ? b[i-1] + b[i] : b[i]);
    }

    int mx = b[k-1];
    int mn = 0;
    for (int i=k; i<n; i++) {
        mn = min(mn, b[i-k]);
        mx = max(mx, b[i] - mn);
    }
    return (mx > 0);
}

void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int lo = 1, hi = n+1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
}

int main() {
    solve();
}