#include <bits/stdc++.h>
using namespace std;

int T, a, b, x, y;

int main () {
    for(cin >> T; T; T--) {
        cin >> a >> b >> x >> y;
        a = abs(a);
        b = abs(b);
        x = abs(x);
        y = abs(y);
        cout << (( __gcd(a, b) == __gcd(x, y) ) ? "YES\n" : "NO\n");
    }
}