#include <bits/stdc++.h>
using namespace std;

const int __multitest = 0;
const int __debug     = 0;

// --
template<typename T>
T In() { T x; cin >> x; return x; }
// --
long long ans = 0;

long long s(long long k) {
    return k*(k+1)/2;
}

void solve() {
    int n = In<int>();
    long long x = In<long long>();
    //
    vector<int> d (n);
    generate(d.begin(), d.end(), In<int>);
    vector<long long> pfx (n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0) pfx[i] = d[i];
        else pfx[i] = pfx[i-1] + d[i];
    }
    //
    int L, R;
    int xx = x;
    long long subans = 0;
    vector<long long> _an (n, 0);
    // -- start at start of month
    L = 0, R = 0;
    while (L < n or R < n) {
        while (xx >= d[R] and R < n) { 
            subans += s(d[R]);
            xx -= d[R];
            R++; 
        }
        if (R >= n-1) ans = max(ans, subans);
        else ans = max(ans, subans + s(xx));
        while (xx < d[R]) {
            xx += d[L];
            subans -= s(d[L]);
            L++;
        }
    }
    // -- start at end of month
    xx = x;
    subans = 0;
    L = n-1, R = n-1;
    while (0 <= L or 0 <= R) {
        while (xx >= d[L] and 0 <= L) {
            subans += s(d[L]);
            xx -= d[L];
            L--;
        }
        if (L <= 0) ans = max(ans, subans);
        else ans = max(ans, subans + s(d[L]) - s(d[L] - xx));
        while (xx < d[L] and L <= R) {
            xx += d[R];
            subans -= s(d[R]);
            R--;
        }
        if (xx < d[L] and L == R) {
            L--, R--;
            subans 
        }
    }
    cout << ans << endl;
}
// --
int main() {
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}