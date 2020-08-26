#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 1;
const int __DEBUGMODE = 0;
#define db if(__DEBUGMODE)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- solve
long long l, r, m;
void solve() {
    cin >> l >> r >> m;
    long long LM = max(1LL, m - r + l);
    long long RM = m + r - l;
    for (long long i = l; i <= r; i++) {
        if (
            (RM - LM + 1>= i) or 
            (LM % i > RM % i) or
            (LM % i == 0)
        ) {
            long long m2;
            if (LM % i == 0) {
                m2 = LM;
            } else {
                m2 = (LM / i + 1) * i;
            }  
            //cout << m2 << endl;

            long long b, c;
            if (m2 - m > 0) { // c > b
                b = l;
                c = l + (m2 - m);
                if (c < l) {
                    b += (l - c);
                    c = l;
                }
            } else { // b > c
                c = l;
                b = l + (m - m2);
                if (b < l) {
                    c += (l - b);
                    b = l;
                }
            }

            cout << i << " " << b << " " << c << endl;
            assert( (m + c - b) % i == 0 );
            return;
        }
    }
}

// --
int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}