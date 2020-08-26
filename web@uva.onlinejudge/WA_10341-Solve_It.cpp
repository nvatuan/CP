#include <bits/stdc++.h>
using namespace std;

long double p, q, r, s, t, u;

int f(long double x) {
    //cout << x << " " << setprecision(9) << fabs(p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u) << '\n';
    return (fabs(p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u) <= 0.00001);
}

int main() {
    //freopen("in", "r", stdin);
    while(cin >> p >> q >> r >> s >> t >> u) {
        long double x = 0.0000;
        while( x < 1.0001 ) {
            if( f(x) ) break;
            x += 0.000005;
        }
        if( x < 1.0001 ) cout << fixed << setprecision(4) << x << '\n';
        else cout << "No solution\n";
    }
}