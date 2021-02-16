#include <bits/stdc++.h>
using namespace std;

long long a, b;

long long calc(long long x) {
    if (x == 1) return (long long)(1e9);
    long long res = x - b;
    long long tmp = a;
    while (tmp > 0) {
        tmp /= x;
        res += 1;
    }
    return res;
}


void solve() {
    cin >> a >> b;
    if (b > a) {
        cout << 1 << endl;
        return;
    }
    long long l = b, r = a+1;
    while (r - l > 3) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        long long f1 = calc(m1), f2 = calc(m2);
        if (f1 > f2) {
            l = m1;
        } else {
            r = m2;
        }
    }

    long long ans = (long long)(2e9);
    for (long long i=l; i<=r; i++) ans = min(ans, calc(i));
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}