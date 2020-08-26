#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

int NextInt() { int x; cin >> x; return x; }
char NextChar() { char x; cin >> x; return x; }
string Next() { string x; cin >> x; return x; }
llong NextLong() { llong x; cin >> x; return x; }
double NextDouble() { double x; cin >> x; return x; }

#define __multitest 1
#define __max_n 200001
// --

int n, k;
int a[__max_n];

int _get(int x) {
    int op = 0;
    for (int i = 0; i < n/2; i++) {
        int j = (n - i - 1);
        int mn = min(a[i], a[j]);
        int mx = max(a[i], a[j]);
        //
        if (mn + mx == x) continue;
        mn += min(k, x - mx - mn); op++;
        if (mn + mx == x) continue;
        op++;
    }
    return op;
}

void solve() {
    n = NextInt(); k = NextInt();
    for (int i = 0; i < n; i++) a[i] = NextInt();
    // -- Ternary search
    int L = 0, R = k*2;
    while (_get(L) == _get(L + 1)) {
        L++;
        if(L >= n) break;
    }
    while (_get(R) == _get(R - 1)) {
        R--;
        if (R < 0) break;
    }
    if (L > R) {
        cout << _get(0) << '\n';
    }
    //
    while ( R - L > 1) {
        int m1 = (L + R)/3;
        int m2 = (L + R)/3*2;
        cerr << "@" << L << " | " << m1 << ";" << m2 << "|" << R << '\n';
        //
        int g1 = _get(m1);
        int g2 = _get(m2);
        if (g1 == g2) {
            L = m1;
            R = m2;
        }
        if (g1 < g2) {
            L = m1;
        }
        if (g1 > g2) {
            R = m2;
        }
    }
    if (_get(L) > _get(R)) cout << L << '\n';
    else cout << R << '\n';
}
// --

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    if (__multitest) {
        for (int t = NextInt(); t; t--) solve();
    }
    else solve();
}