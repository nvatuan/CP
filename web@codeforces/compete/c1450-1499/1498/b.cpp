#include <bits/stdc++.h>
using namespace std;

int n, w;

void solve() {
    map<int, int> cnt;
    cin >> n >> w;
    for (int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }

    int counter = n;
    int ans = 0;
    while (counter > 0) {
        ans++;
        long long spare = 0;
        for (int b=32; b>=0; b--) {
            if (w & (1LL<<b)) spare += 1;
            // cerr << (1LL<<b) << ": " << spare << endl;

            if (cnt[(1LL<<b)] > 0) {
                long long mn = min(cnt[(1LL<<b)]*1LL, spare);

                cnt[(1LL<<b)] -= mn;
                spare -= mn;
                counter -= mn;
            }

            spare <<= 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}