#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int &i : a) cin >> i;

    map<int, int> cnt;
    for (int i : a) {
        cnt[i%m]++;
    }

    int ans = (cnt[0] == 0 ? 0 : 1);

    if (m%2==0 && cnt[m/2]>0) ans++;

    // cerr << "@" << ans << endl;
    for (int md=1; md<m; md++) {
        // cerr << md << ' ' << ans << endl;
        int md2 = m - md;
        if (md2 <= md) break;
        if (!cnt[md] && !cnt[md2]) continue;

        if (cnt[md] and cnt[md2]) {
            ans++;
            ans += (abs(cnt[md] - cnt[md2]) > 1 ? abs(cnt[md]-cnt[md2])-1 : 0);
            continue;
        }

        ans += cnt[md];
        ans += cnt[md2];
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}