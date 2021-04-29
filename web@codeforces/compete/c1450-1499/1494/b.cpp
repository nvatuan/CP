#include <bits/stdc++.h>
using namespace std;

int n, U, L, R, D;

void solve() {
    cin >> n;
    cin >> U >> R >> D >> L;
    for (int state=0; state<(1<<4); state++) {
        int ul = ((state>>0)&1);
        int ur = ((state>>1)&1);
        int dl = ((state>>2)&1);
        int dr = ((state>>3)&1);

        int u, l, r, d;
        tie(u, l, r, d) = tie(U, L, R, D);
        if (ul) {
            u--; l--;
        }
        if (ur) {
            u--, r--;
        }
        if (dl) {
            d--, l--;
        }
        if (dr) {
            d--, r--;
        }
        int poss = 1;
        for (int x : {u, l, r, d}) {
            poss &= ((0 <= x) && (x <= n-2));
        }
        if (poss) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}