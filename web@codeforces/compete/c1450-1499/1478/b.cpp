#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q, d;
    cin >> q >> d;
    for (int i=0; i<q; i++) {
        int x;
        scanf("%d", &x);

        if (x >= d*10+d) {
            printf("YES\n");
        } else {
            int pos = (x/10 == d);
            while (x >= d) {
                if (x % 10 == d) {
                    pos = true;
                    break;
                }
                x -= d;
            }
            printf(pos ? "YES\n" : "NO\n");
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}