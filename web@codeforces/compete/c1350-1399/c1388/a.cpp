#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n >= 31) {
        printf("YES\n");
        for (int i : {6, 10, 14}) n -= i;
        if (n == 14) {
            printf("6 10 15 13\n");
        } else
        if (n == 10) {
            printf("6 10 15 9\n");
        } else
        if (n == 6) {
            printf("6 10 15 5\n");
        } else {
            printf("6 10 14 %d\n", n);
        }
    } else {
        printf("NO\n");
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}