#include <bits/stdc++.h>
using namespace std;

const int DEBUG = 0;
#define db if(DEBUG)

typedef long long ll;

int n;
ll x[(int)(2e5)], t[(int)(2e5)];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i] >> x[i];
    }
    t[n] = (ll)(1e16);

    ll pos = 0, tnow = 0;
    int cmd = 0;

    int ans = 0;
    while (cmd < n) {
        ll posto = x[cmd];
        if (tnow < t[cmd]) tnow = t[cmd];
        ll tto = abs(x[cmd] - pos) + tnow;

        int nxtCmd = cmd+1;
        while (nxtCmd < n && t[nxtCmd] < tto) nxtCmd++;

        db printf("pos=%lld, tnow=%lld\nposto=%lld, tto=%lld\nnxtCmd=%lld\n\n", pos, tnow, posto, tto, nxtCmd);

        for (int i=cmd; i<nxtCmd; i++) {
            ll pospass = x[i];
            ll tpass = (abs(pospass - pos) + tnow);
            if (
                (pos <= pospass && pospass <= posto)
                    or 
                (pos >= pospass && pospass >= posto)
            ) {
                if ((tpass >= t[i] && tpass <= t[i+1])) ans++;
            }
        }
        db printf("ans=%d\n", ans);

        cmd = nxtCmd;
        pos = posto;
        tnow = tto;
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}