#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

int NextInt() { int x; cin >> x; return x; }
char NextChar() { char x; cin >> x; return x; }
string Next() { string x; cin >> x; return x; }
llong NextLong() { llong x; cin >> x; return x; }
double NextDouble() { double x; cin >> x; return x; }

#define __multitest 1
// --

void solve() {
    int n = NextInt();
    for (int i = 2; i < 31; i++) {
        if ( n % ((1<<i)-1) == 0 ) {
            cout << (n / ((1<<i)-1)) << '\n';
            return;
        }
    }
}

// --

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
    if (__multitest) {
        for (int t = NextInt(); t; t--) solve();
    }
    else solve();
}