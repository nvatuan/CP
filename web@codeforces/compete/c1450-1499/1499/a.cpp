#include <bits/stdc++.h>
using namespace std;

int n, k1, k2, h1, h2;
int w, b;

void solve() {
    cin >> n >> k1 >> k2;
    cin >> w >> b;

    h1 = n-k1;
    h2 = n-k2;

    int poss=1;
    while (w > 0) {
        if (k1 >= 2) {
            k1 -= 2;
            w--;
        } else {
            if (k2 >= 2) {
                k2 -= 2;
                w--;
            } else {
                if (k1 > 0 && k2 > 0) {
                    k1--; k2--;
                    w--;
                } else {
                    poss = 0;
                    break;
                }
            }
        }
    }
    while (b > 0) {
        if (h1 >= 2) {
            h1 -= 2;
            b--;
        } else {
            if (h2 >= 2) {
                h2 -= 2;
                b--;
            } else {
                if (h1 > 0 && h2 > 0) {
                    h1--; h2--;
                    b--;
                } else {
                    poss = 0;
                    break;
                }
            }
        }
    }
    // cerr << w << b << endl;
    // cerr << k1 << ' ' << k2 << " | " << h1 << ' ' << h2 << endl;
    cout << (poss ? "YES" : "NO")  << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}