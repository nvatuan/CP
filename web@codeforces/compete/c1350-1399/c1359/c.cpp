#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 1;
const int __DEBUGMODE = 0;
#define db if(__DEBUGMODE)

template<typename T>
T In() { T x; cin >> x; return x; }

// --
int h, c, t;

double f(long long x) {
    assert(x % 2 == 1);
    return ( (x/2+1)*h + (x/2)*c)*1.0/(x);
}

double MIN_ABSOLUTE;
int times;

void solve() {
    cin >> h >> c >> t;
    //
    MIN_ABSOLUTE = abs(((h+c)*1.0/2) - t);
    times = 2;
    db cout << "MIN_AB = " << MIN_ABSOLUTE << endl;
    db cout << "times = " << times << endl;
    //
    int L = 0; int R = 1000000/2;
    while ( R - L > 1 ) {
        int mid = (L + R) / 2;
        int odd = 2*mid + 1;
        if (f(odd) > t) {
            L = mid;
        } else {
            R = mid;
        }
        db cout << "@" << mid << " " << f(odd) << endl;
    }
    //
    db cout << "L = " << L << " | R = " << R << endl;
    if ( abs(f(2*L + 1) - t) < MIN_ABSOLUTE) {
        times = (2*L + 1);
        MIN_ABSOLUTE = abs(f(2*L + 1) - t);
    }
    if ( abs(f(2*R + 1) - t) < MIN_ABSOLUTE) times = (2*R + 1);
    db cout << MIN_ABSOLUTE << endl;
    cout << times << endl;
}

// --
int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}