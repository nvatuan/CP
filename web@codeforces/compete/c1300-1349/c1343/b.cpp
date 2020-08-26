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
int a[200001];

void solve() {
    int n = NextInt();
    if ( n % 4 == 0 ) {
        cout << "YES\n";
        fill(a, a + (n/2), 2);
        fill(a + (n/2), a+n, 1); 
        for (int i = (n/2 + 1); i < n; i++) {
            a[i] = (a[i-1] + 2);
            a[i - (n/2)] = (a[i - (n/2) - 1] + 2);
        }
        a[n-1] += (n/2);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << '\n';
    } else {
        cout << "NO\n";
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